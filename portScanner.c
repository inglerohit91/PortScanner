#include "portScanner.h"
#include<sys/time.h>
/*==============================*/
/*	Global Variables 	*/
/*==============================*/
int job_index = 0;		   
int no_of_threads = 0; 	
int scan = 1;	 
int no_of_jobs;
int no_of_scans = 0;
int version_flag = 0;
int ** scan_list=NULL;
struct job_queue ** job_q;
struct result_table ** result_t = NULL;
unsigned char ** ip_list = NULL;	/* For storing IPs*/
extern char service_name[1024][50];
pthread_mutex_t mymutex=PTHREAD_MUTEX_INITIALIZER;
int syn_flag = 0, ack_flag =0, xmas_flag = 0, null_flag = 0, fin_flag = 0, udp_flag = 0;

/*==============================*/
/*		Main	 	*/
/*==============================*/

int main(int argc, char ** argv)
{
struct timeval  tv1, tv2;
gettimeofday(&tv1, NULL);
int p =	0;
int q = 0;
no_of_jobs = 0;
int index = 0;
int ar_flag[6] = {0,0,0,0,0,0};
ps_args_t ps_args;
int i = 0;

	ip_list = (unsigned char**) malloc(IP_LIST_SIZE * sizeof(unsigned char*));			/* For storing IPs*/
	unsigned int ** port_list = NULL;										/* For storing ports */
	port_list = parse_args(argc, argv, &ps_args, ip_list, port_list);						/* Parse Command line arguments */
	no_of_jobs = ps_args.total_ip_count * ps_args.total_port_count * no_of_scans;					/* Total no of jobs to be done */
	job_q = (struct job_queue **) malloc(no_of_jobs * sizeof(struct job_queue *));					/* Malloc for the job queue */
        	
	/* Scan flag calculations */
	/*========================*/	
	if (syn_flag == 1)	ar_flag[0] = 1;
	if (null_flag == 1)	ar_flag[1] = 2;
	if (fin_flag == 1)	ar_flag[2] = 3;
	if (xmas_flag == 1)	ar_flag[3] = 4;
	if (ack_flag == 1)	ar_flag[4] = 5;
	if (udp_flag == 1)	ar_flag[5] = 6;

	scan_list = (int**)malloc(no_of_scans * sizeof(int*));
	for (i=0; i<no_of_scans; i++)	{
		scan_list[i] = (int*) malloc(sizeof (int));
	}
	int f = 0;
	for (i = 0; i<6; i++)	{
		if(ar_flag[i]!=0)	{
			*scan_list[f] = ar_flag[i];
			f++;
		}
	}
	
	/* Populating the job queue with data from ip list, port list and scan type */
	/*==========================================================================*/
	
	for (p=0; p<ps_args.total_ip_count; p++)
	{
		for (q=0; q<ps_args.total_port_count; q++)
		{
			for (i=0; i<no_of_scans; i++)	
			{
				job_q[index] = (struct job_queue*) malloc (sizeof (struct job_queue));
				strncpy(job_q[index]->q_ip, (char*)ip_list[p], strlen((char*)ip_list[p])+1 );
				job_q[index]->q_port = *port_list[q];
				job_q[index]->q_scan = *scan_list[i];
				index++;

			}
		}
	}

pthread_t mythread_new[no_of_threads];	
int k = 0;
	/*	Thread Creation */
	/*======================*/
	printf("\nScanning.");
	for (k = 0; k<no_of_threads; k++) {
        	if ( pthread_create( &mythread_new[k], NULL, my_function,NULL) ) {
            		printf("error creating thread.");
                	abort();
		}
	}

	/*	Thread joininig */
	/*======================*/

	for (k = 0; k<no_of_threads; k++)  {
  		if ( pthread_join( mythread_new[k], NULL) ) {
    			printf("error joining thread.");
    			abort();
		} 
	}	

	gettimeofday(&tv2, NULL);
	printf ("\n\nScanning took %.2f seconds\n\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
	
	/* Populating the concluding data structure */
	/*==========================================*/
int result_count = ps_args.total_ip_count * ps_args.total_port_count;
	
	result_t = (struct result_table **) malloc(result_count * sizeof(struct result_table*));
	for (i = 0; i<result_count; i++)
		result_t[i] = (struct result_table*) malloc (sizeof (struct result_table));
		
	populateConclusionTable(result_count,ps_args.total_port_count);



	/* Freeing the data structures used so far */
	/*=========================================*/	
	for(i = 0; i< ps_args.total_ip_count; i++)
		free(ip_list[i]);
	free(ip_list);
	for(i = 0; i< ps_args.total_port_count; i++)
		free(port_list[i]);
	free(port_list);
	for(i = 0; i< no_of_jobs; i++)
		free(job_q[i]);
	free(job_q);
	for(i = 0; i< no_of_scans; i++)
		free(scan_list[i]);
	free(scan_list);
	for (i = 0; i<result_count; i++)
		free(result_t[i]);
	free(result_t);

	return 0;

	/* END MAIN */
}
