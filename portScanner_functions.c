#include "portScanner.h"
/* Array for storing service name */
char service_version[6][30];
char service_name[1024][50]	= {	"tcpmux", //1
					"compressnet", //2
					"compressnet", //3
					"Unassigned", //4
					"rje", //5
					"Unassigned", //6
					"echo", //7
					"Unassigned", //8
					"discard", //9
					"Unassigned", //10
					"systat", //11
					"Unassigned", //12
					"daytime", //13
					"Unassigned", //14
					"Unassigned", //15
					"Unassigned", //16
					"qotd", //17
					"msp", //18
					"chargen", //19
					"ftp-data", //20
					"ftp", //21
					"ssh", //22
					"telnet", //23
					"priv-mail-system", //24
					"smtp", //25
					"Unassigned", //26
					"nsw-fe", //27
					"Unassigned", //28
					"msg-icp", //29
					"Unassigned", //30
					"msg-auth", //31
					"Unassigned", //32
					"dsp", //33
					"Unassigned", //34
					"priv-printer-server", //35
					"Unassigned", //36
					"time", //37
					"rap", //38
					"rlp", //39
					"Unassigned", //40
					"graphics", //41
					"nameserver", //42
					"nicname", //43
					"mpm-flags", //44
					"mpm", //45
					"mpm-send", //46
					"ni-ftp", //47
					"auditd", //48
					"tacacs", //49
					"re-mail-ck", //50
					"Reserved", //51
					"xns-time", //52
					"domain", //53
					"xns-ch", //54
					"isi-gl", //55
					"xns-auth", //56
					"priv-terminal-access", //57
					"xns-mail", //58
					"priv-file-service", //59
					"Unassigned", //60
					"ni-mail", //61
					"acas", //62
					"whoispp", //63
					"covia", //64
					"tacacs-ds", //65
					"sql-net", //66
					"bootps", //67
					"bootpc", //68
					"tftp", //69
					"gopher", //70
					"netrjs-1", //71
					"netrjs-2", //72
					"netrjs-3", //73
					"netrjs-4", //74
					"Unassigned", //75
					"deos", //76
					"private RJE service", //77
					"vettcp", //78
					"finger", //79
					"http", //80
					"Unassigned", //81
					"xfer", //82
					"mit-ml-dev", //83
					"ctf", //84
					"mit-ml-dev", //85
					"mfcobol", //86
					"private terminal link", //87
					"kerberos", //88
					"su-mit-tg", //89
					"dnsix", //90
					"mit-dov", //91
					"npp", //92
					"dcp", //93
					"objcall", //94
					"supdup", //95
					"dixie", //96
					"swift-rvf", //97
					"tacnews", //98
					"metagram", //99
					"Unassigned", //100
					"hostname", //101
					"iso-tsap", //102
					"gppitnp", //103
					"acr-nema", //104
					"csnet-ns", //105
					"3com-tsmux", //106
					"rtelnet", //107
					"snagas", //108
					"pop2", //109
					"pop3", //110
					"sunrpc", //111
					"mcidas", //112
					"auth", //113
					"Unassigned", //114
					"sftp", //115
					"ansanotify", //116
					"uucp-path", //117
					"sqlserv", //118
					"nntp", //119
					"cfdptkt", //120
					"erpc", //121
					"smakynet", //122
					"ntp", //123
					"ansatrader", //124
					"locus-map", //125
					"nxedit", //126
					"locus-con", //127
					"gss-xlicen", //128
					"pwdgen", //129
					"cisco-fna", //130
					"cisco-fna", //131
					"cisco-sys", //132
					"statsrv", //133
					"ingres-net", //134
					"epmap", //135
					"profile", //136
					"netbios-ns", //137
					"netbios-dgm", //138
					"netbios-ssn", //139
					"emfis-data", //140
					"emfis-cntl", //141
					"bl-idm", //142
					"imap", //143
					"uma", //144
					"uaac", //145
					"iso-tp()", //146
					"iso-ip", //147
					"jargon", //148
					"aed-512", //149
					"sql-net", //150
					"hems", //151
					"bftp", //152
					"sgmp", //153
					"netsc-prod", //154
					"netsc-dev", //155
					"sqlsrv", //156
					"knet-cmp", //157
					"pcmail-srv", //158
					"nss-routing", //159
					"sgmp-traps", //160
					"snmp", //161
					"snmptrap", //162
					"cmip-man", //163
					"cmip-agent", //164
					"xns-courier", //165
					"s-net", //166
					"namp", //167
					"rsvd", //168
					"send", //169
					"print-srv", //170
					"multiplex", //171
					"cl-1", //172
					"xyplex-mux", //173
					"mailq", //174
					"vmnet", //175
					"genrad-mux", //176
					"xdmcp", //177
					"nextstep", //178
					"bgp", //179
					"ris", //180
					"unify", //181
					"audit", //182
					"ocbinder", //183
					"ocserver", //184
					"remote-kis", //185
					"kis", //186
					"aci", //187
					"mumps", //188
					"qft", //189
					"gacp", //190
					"prospero", //191
					"osu-nms", //192
					"smp", //193
					"irc", //194
					"dn6-nlm-aud", //195
					"dn6-smm-red", //196
					"dls", //197
					"dls-mon", //198
					"smux", //199
					"src", //200
					"at-rtmp", //201
					"at-nbp", //202
					"at-3", //203
					"at-echo", //204
					"at-5", //205
					"at-zis", //206
					"at-7", //207
					"at-8", //208
					"qmtp", //209
					"ANSI z39.50", //210
					"TEXAS Instruments 914c/g", //211
					"anet", //212
					"ipx", //213
					"vmpwscs", //214
					"softpc", //215
					"CAllic", //216
					"dbase", //217
					"mpp", //218
					"uarps", //219
					"imap3", //220
					"fln-spx", //221
					"rsh-spx", //222
					"cdc", //223
					"masqdialer", //224
					"Reserved", //225
					"Reserved", //226
					"Reserved", //227
					"Reserved", //228
					"Reserved", //229
					"Reserved", //230
					"Reserved", //231
					"Reserved", //232
					"Reserved", //233
					"Reserved", //234
					"Reserved", //235
					"Reserved", //236
					"Reserved", //237
					"Reserved", //238
					"Reserved", //239
					"Reserved", //240
					"Reserved", //241
					"direct", //242
					"sur-meas", //243
					"inbusiness", //244
					"link", //245
					"dsp3270", //246
					"subntbcst-tftp", //247
					"bhfhs", //248
					"Reserved", //249
					"Reserved", //250
					"Reserved", //251
					"Reserved", //252
					"Reserved", //253
					"Reserved", //254
					"Reserved", //255
					"rap", //256
					"set", //257
					"Unassigned", //258
					"esro-gen", //259
					"openport", //260
					"nsiiops", //261
					"arcisdms", //262
					"hdap", //263
					"bgmp", //264
					"x-bone-ctl", //265
					"sst", //266
					"td-service", //267
					"td-replica", //268
					"manet", //269
					"Reserved", //270
					"pt-tls", //271
					"Unassigned", //272
					"Unassigned", //273
					"Unassigned", //274
					"Unassigned", //275
					"Unassigned", //276
					"Unassigned", //277
					"Unassigned", //278
					"Unassigned", //279
					"http-mgmt", //280
					"personal-link", //281
					"cableport-ax", //282
					"rescap", //283
					"corerjd", //284
					"Unassigned", //285
					"fxp", //286
					"k-block", //287
					"Unassigned", //288
					"Unassigned", //289
					"Unassigned", //290
					"Unassigned", //291
					"Unassigned", //292
					"Unassigned", //293
					"Unassigned", //294
					"Unassigned", //295
					"Unassigned", //296
					"Unassigned", //297
					"Unassigned", //298
					"Unassigned", //299
					"Unassigned", //300
					"Unassigned", //301
					"Unassigned", //302
					"Unassigned", //303
					"Unassigned", //304
					"Unassigned", //305
					"Unassigned", //306
					"Unassigned", //307
					"novastorbakcup", //308
					"entrusttime", //309
					"bhmds", //310
					"asip-webadmin", //311
					"vslmp", //312
					"magenta-logic", //313
					"opalis-robot", //314
					"dpsi", //315
					"decauth", //316
					"zannet", //317
					"pkix-timestamp", //318
					"ptp-event", //319
					"ptp-general", //320
					"pip", //321
					"rtsps", //322
					"Reserved", //323
					"rpki-rtr-tls (TCP); Reserved (UDP)", //324
					"Reserved", //325
					"Reserved", //326
					"Reserved", //327
					"Reserved", //328
					"Reserved", //329
					"Reserved", //330
					"Reserved", //331
					"Reserved", //332
					"texar", //333
					"Reserved", //334
					"Reserved", //335
					"Reserved", //336
					"Reserved", //337
					"Reserved", //338
					"Reserved", //339
					"Reserved", //340
					"Reserved", //341
					"Reserved", //342
					"Reserved", //343
					"pdap", //344
					"pawserv", //345
					"zserv", //346
					"fatserv", //347
					"csi-sgwp", //348
					"mftp", //349
					"matip-type-a", //350
					"matip-type-b; bhoetty", //351
					"dtag-ste-sb; bhoedap4", //352
					"ndsauth", //353
					"bh611", //354
					"datex-asn", //355
					"cloanto-net-1", //356
					"bhevent", //357
					"shrinkwrap", //358
					"nsrmp", //359
					"scoi2odialog", //360
					"semantix", //361
					"srssend", //362
					"rsvp-tunnel", //363
					"aurora-cmgr", //364
					"dtk", //365
					"odmr", //366
					"mortgageware", //367
					"qbikgdp", //368
					"rpc2portmap", //369
					"codaauth2", //370
					"clearcase", //371
					"ulistproc", //372
					"legent-1", //373
					"legent-2", //374
					"hassle", //375
					"nip", //376
					"tnETOS", //377
					"dsETOS", //378
					"is99c", //379
					"is99s", //380
					"hp-collector", //381
					"hp-managed-node", //382
					"hp-alarm-mgr", //383
					"arms", //384
					"ibm-app", //385
					"asa", //386
					"aurp", //387
					"unidata-ldm", //388
					"ldap", //389
					"uis", //390
					"synotics-relay", //391
					"synotics-broker", //392
					"meta5", //393
					"embl-ndt", //394
					"netcp", //395
					"netware-ip", //396
					"mptn", //397
					"kryptolan", //398
					"iso-tsap-c2", //399
					"osb-sd", //400
					"ups", //401
					"genie", //402
					"decap", //403
					"nced", //404
					"ncld", //405
					"imsp", //406
					"timbuktu", //407
					"prm-sm", //408
					"prm-nm", //409
					"decladebug", //410
					"rmt", //411
					"synoptics-trap", //412
					"smsp", //413
					"infoseek", //414
					"bnet", //415
					"silverplatter", //416
					"onmux", //417
					"hyper-g", //418
					"ariel1", //419
					"smpte", //420
					"ariel2", //421
					"ariel3", //422
					"opc-job-start", //423
					"opc-job-track", //424
					"icad-el", //425
					"smartsdp", //426
					"svrloc", //427
					"OCS_CMU", //428
					"OCS_AMU", //429
					"utmpsd", //430
					"utmpcd", //431
					"iasd", //432
					"nnsp", //433
					"mobileip-agent", //434
					"mobileip-mn", //435
					"dna-cml", //436
					"comscm", //437
					"dsfgw", //438
					"dasp", //439
					"sgcp", //440
					"decvms-sysmgt", //441
					"cvc-hostd", //442
					"https", //443
					"snpp", //444
					"Microsoft-ds", //445
					"ddm-rdb", //446
					"ddm-dfm", //447
					"ddm-ssl", //448
					"as-servermap", //449
					"tserver", //450
					"sfs-smp-net", //451
					"sfs-config", //452
					"CreativeServer", //453
					"ContentServer", //454
					"CreativePartnr", //455
					"macon-tcp (TCP); macon_udp (UDP)", //456
					"scohelp", //457
					"appleqtc", //458
					"ampr-rcmd", //459
					"skornk", //460
					"datasurfsrv", //461
					"datasurfsrvsec", //462
					"alpes", //463
					"kpasswd", //464
					"urd (TCP); igmpv3lite (UDP)", //465
					"digital-vrc", //466
					"mylex-mapd", //467
					"photuris", //468
					"rcp", //469
					"scx-proxy", //470
					"mondex", //471
					"ljk-login", //472
					"hybrid-pop", //473
					"tn-tl-w1 (TCP); tn-tl-w2 (UDP)", //474
					"tcpnethaspsrv", //475
					"tn-tl-fd1", //476
					"ss7ns", //477
					"spsc", //478
					"iafserver", //479
					"iafdbase", //480
					"ph", //481
					"bgs-nsi", //482
					"ulpnet", //483
					"integra-sme", //484
					"powerburst", //485
					"avian", //486
					"saft", //487
					"gss-http", //488
					"nest-protocol", //489
					"micom-pfs", //490
					"go-login", //491
					"ticf-1", //492
					"ticf-2", //493
					"pov-ray", //494
					"intecourier", //495
					"pim-rp-disc", //496
					"retrospect", //497
					"siam", //498
					"iso-ill", //499
					"isakmp", //500
					"stmf", //501
					"mbap", //502
					"intrinsa", //503
					"citadel", //504
					"mailbox-lm", //505
					"ohimsrv", //506
					"crs", //507
					"xvttp", //508
					"snare", //509
					"fcp", //510
					"passgo", //511
					"exec (TCP); comsat/biff (UDP)", //512
					"login (TCP); who (UDP)", //513
					"shell (TCP); syslog (UDP)", //514
					"printer", //515
					"videotex", //516
					"talk", //517
					"ntalk", //518
					"utime", //519
					"efs (TCP); router (UDP)", //520
					"ripng", //521
					"ulp", //522
					"ibm-db2", //523
					"ncp", //524
					"timed", //525
					"tempo", //526
					"stx", //527
					"custix", //528
					"irc-serv", //529
					"courier", //530
					"conference", //531
					"netnews", //532
					"netwall", //533
					"windream", //534
					"iiop", //535
					"opalis-rdv", //536
					"nmsp", //537
					"gdomap", //538
					"apertus-ldp", //539
					"uucp", //540
					"uucp-rlogin", //541
					"commerce", //542
					"klogin", //543
					"kshell", //544
					"appleqtcsrvr", //545
					"dhcpv6-client", //546
					"dhcpv6-server", //547
					"afpovertcp", //548
					"idfp", //549
					"new-rwho", //550
					"cybercash", //551
					"devshr-nts", //552
					"pirp", //553
					"rtsp", //554
					"dsf", //555
					"remotefs", //556
					"openvms-sysipc", //557
					"sdnskmp", //558
					"teedtap", //559
					"monitor", //560
					"monitor", //561
					"chshell", //562
					"nntps", //563
					"9pfs", //564
					"whoami", //565
					"streettalk", //566
					"banyan-rpc", //567
					"ms-shuttle", //568
					"ms-rome", //569
					"meter", //570
					"meter", //571
					"sonar", //572
					"banyan-vip", //573
					"ftp-agent", //574
					"vemmi", //575
					"ipcd", //576
					"vnas", //577
					"ipdd", //578
					"decbsrv", //579
					"sntp-heartbeat", //580
					"bdp", //581
					"scc-security", //582
					"philips-vc", //583
					"keyserver", //584
					"De-registered", //585
					"password-chg", //586
					"submission", //587
					"cal", //588
					"eyelink", //589
					"tns-cml", //590
					"http-alt", //591
					"eudora-set", //592
					"http=rpc-epmap", //593
					"tpip", //594
					"cab-protocol", //595
					"smsd", //596
					"ptcnameservice", //597
					"sco-websrvrmg3", //598
					"acp", //599
					"ipcserver", //600
					"syslog-conn", //601
					"xmlrpc-beep", //602
					"idxp", //603
					"tunnel", //604
					"soap-beep", //605
					"urm", //606
					"nqs", //607
					"sift-uft", //608
					"npmp-trap", //609
					"npmp-local", //610
					"npmp-gui", //611
					"hmmp-ind", //612
					"hmmp-op", //613
					"sshell", //614
					"sco-inetmgr", //615
					"sco-sysmgr", //616
					"sco-dtmgr", //617
					"dei-icda", //618
					"compaq-evm", //619
					"sco-websrvrmgr", //620
					"escp-ip", //621
					"collaborator", //622
					"oob-ws-http (TCP); asf-rmcp (UDP)", //623
					"cryptoadmin", //624
					"dec-dlm", //625
					"asia", //626
					"passgo-tivoli", //627
					"qmqp", //628
					"3com-amp3", //629
					"rda", //630
					"ipp", //631
					"bmpp", //632
					"servstat", //633
					"ginad", //634
					"rlzdbase", //635
					"ldaps", //636
					"lanserver", //637
					"mcns-sec", //638
					"msdp", //639
					"entrust-sps", //640
					"repcmd", //641
					"esro-emsdp", //642
					"sanity", //643
					"dwr", //644
					"pssc", //645
					"ldp", //646
					"dhcp-failover", //647
					"rrp", //648
					"cadview-3d", //649
					"obex", //650
					"ieee-mms", //651
					"hello-port", //652
					"repscmd", //653
					"aodv", //654
					"tinc", //655
					"spmp", //656
					"rmc", //657
					"tenfold", //658
					"Removed", //659
					"mac-srvr-admin", //660
					"hap", //661
					"pftp", //662
					"purenoise", //663
					"oob-ws-https (TCP); asf-secure-rmcp (UDP)", //664
					"sun-dr", //665
					"mdqs/doom", //666
					"disclose", //667
					"mecomm", //668
					"meregister", //669
					"vacdsm-sws", //670
					"vacdsm-app", //671
					"vpps-qua", //672
					"cimplex", //673
					"acap", //674
					"dctp", //675
					"vps-via", //676
					"vpp", //677
					"ggf-ncp", //678
					"mrm", //679
					"entrust-aaas", //680
					"entrust-aams", //681
					"xfr", //682
					"corba-iiop", //683
					"corba-iiop-ssl", //684
					"mdc-portmapper", //685
					"hcp-wismar", //686
					"asipregistry", //687
					"realm-rusd", //688
					"nmap", //689
					"vatp", //690
					"msexch-routing", //691
					"hyperwave-isp", //692
					"connendp", //693
					"ha-cluster", //694
					"ieee-mms-ssl", //695
					"rushd", //696
					"uuidgen", //697
					"olsr", //698
					"accessnetwork", //699
					"epp", //700
					"lmp", //701
					"iris-beep", //702
					"Unassigned", //703
					"elcsd", //704
					"agentx", //705
					"silc", //706
					"borland-dsj", //707
					"Unassigned", //708
					"entrust-kmsh", //709
					"entrust-ash", //710
					"cisco-tdp", //711
					"tbrpf", //712
					"iris-xpc", //713
					"iris-xpcs", //714
					"iris-lwz", //715
					"pana", //716
					"Unassigned", //717
					"Unassigned", //718
					"Unassigned", //719
					"Unassigned", //720
					"Unassigned", //721
					"Unassigned", //722
					"Unassigned", //723
					"Unassigned", //724
					"Unassigned", //725
					"Unassigned", //726
					"Unassigned", //727
					"Unassigned", //728
					"netviewdm1", //729
					"netviewdm2", //730
					"netviewdm3", //731
					"Unassigned", //732
					"Unassigned", //733
					"Unassigned", //734
					"Unassigned", //735
					"Unassigned", //736
					"Unassigned", //737
					"Unassigned", //738
					"Unassigned", //739
					"Unassigned", //740
					"netgw", //741
					"netrcs", //742
					"Unassigned", //743
					"flexlm", //744
					"Unassigned", //745
					"Unassigned", //746
					"fujitsu-dev", //747
					"ris-cm", //748
					"kerberos-adm", //749
					"rfile", //750
					"pump", //751
					"qrh", //752
					"rrh", //753
					"tell", //754
					"Unassigned", //755
					"Unassigned", //756
					"Unassigned", //757
					"nlogin", //758
					"con", //759
					"ns", //760
					"rxe", //761
					"quotad", //762
					"cycleserv", //763
					"omserv", //764
					"webster", //765
					"Unassigned", //766
					"phonebook", //767
					"Unassigned", //768
					"vid", //769
					"cadlock", //770
					"rtip", //771
					"cycleserv2", //772
					"submit (TCP); notify (UDP)", //773
					"rpasswd (TCP); acmaint-dbd (UDP)", //774
					"entomb (TCP); acmaint-transd (UDP)", //775
					"wpages", //776
					"multiling-http", //777
					"Unassigned", //778
					"Unassigned", //779
					"wpgs", //780
					"Unassigned", //781
					"Unassigned", //782
					"Unassigned", //783
					"Unassigned", //784
					"Unassigned", //785
					"Unassigned", //786
					"Unassigned", //787
					"Unassigned", //788
					"Unassigned", //789
					"Unassigned", //790
					"Unassigned", //791
					"Unassigned", //792
					"Unassigned", //793
					"Unassigned", //794
					"Unassigned", //795
					"Unassigned", //796
					"Unassigned", //797
					"Unassigned", //798
					"Unassigned", //799
					"mdbs-daemon", //800
					"device", //801
					"mbap-s", //802
					"Unassigned", //803
					"Unassigned", //804
					"Unassigned", //805
					"Unassigned", //806
					"Unassigned", //807
					"Unassigned", //808
					"Unassigned", //809
					"fcp-udp", //810
					"Unassigned", //811
					"Unassigned", //812
					"Unassigned", //813
					"Unassigned", //814
					"Unassigned", //815
					"Unassigned", //816
					"Unassigned", //817
					"Unassigned", //818
					"Unassigned", //819
					"Unassigned", //820
					"Unassigned", //821
					"Unassigned", //822
					"Unassigned", //823
					"Unassigned", //824
					"Unassigned", //825
					"Unassigned", //826
					"Unassigned", //827
					"itm-mcell-s", //828
					"pkix-3-ca-ra", //829
					"netconf-ssh", //830
					"netconf-beep", //831
					"netconfsoaphttp", //832
					"netconfsoapbeep", //833
					"Unassigned", //834
					"Unassigned", //835
					"Unassigned", //836
					"Unassigned", //837
					"Unassigned", //838
					"Unassigned", //839
					"Unassigned", //840
					"Unassigned", //841
					"Unassigned", //842
					"Unassigned", //843
					"Unassigned", //844
					"Unassigned", //845
					"Unassigned", //846
					"dhcp-failover2", //847
					"gdoi", //848
					"Unassigned", //849
					"Unassigned", //850
					"Unassigned", //851
					"Unassigned", //852
					"Unassigned", //853
					"Unassigned", //854
					"Unassigned", //855
					"Unassigned", //856
					"Unassigned", //857
					"Unassigned", //858
					"Unassigned", //859
					"iscsi", //860
					"owamp-control", //861
					"twamp-control", //862
					"Unassigned", //863
					"Unassigned", //864
					"Unassigned", //865
					"Unassigned", //866
					"Unassigned", //867
					"Unassigned", //868
					"Unassigned", //869
					"Unassigned", //870
					"Unassigned", //871
					"Unassigned", //872
					"rsync", //873
					"Unassigned", //874
					"Unassigned", //875
					"Unassigned", //876
					"Unassigned", //877
					"Unassigned", //878
					"Unassigned", //879
					"Unassigned", //880
					"Unassigned", //881
					"Unassigned", //882
					"Unassigned", //883
					"Unassigned", //884
					"Unassigned", //885
					"iclcnet-locate", //886
					"iclcnet-svinfo", //887
					"accessbuilder/cddbp", //888
					"Unassigned", //889
					"Unassigned", //890
					"Unassigned", //891
					"Unassigned", //892
					"Unassigned", //893
					"Unassigned", //894
					"Unassigned", //895
					"Unassigned", //896
					"Unassigned", //897
					"Unassigned", //898
					"Unassigned", //899
					"omginitialrefs", //900
					"smpnameres", //901
					"ideafarm-door", //902
					"ideafarm-panic", //903
					"Unassigned", //904
					"Unassigned", //905
					"Unassigned", //906
					"Unassigned", //907
					"Unassigned", //908
					"Unassigned", //909
					"kink", //910
					"xact-backup", //911
					"apex-mesh", //912
					"apex-edge", //913
					"Unassigned", //914
					"Unassigned", //915
					"Unassigned", //916
					"Unassigned", //917
					"Unassigned", //918
					"Unassigned", //919
					"Unassigned", //920
					"Unassigned", //921
					"Unassigned", //922
					"Unassigned", //923
					"Unassigned", //924
					"Unassigned", //925
					"Unassigned", //926
					"Unassigned", //927
					"Unassigned", //928
					"Unassigned", //929
					"Unassigned", //930
					"Unassigned", //931
					"Unassigned", //932
					"Unassigned", //933
					"Unassigned", //934
					"Unassigned", //935
					"Unassigned", //936
					"Unassigned", //937
					"Unassigned", //938
					"Unassigned", //939
					"Unassigned", //940
					"Unassigned", //941
					"Unassigned", //942
					"Unassigned", //943
					"Unassigned", //944
					"Unassigned", //945
					"Unassigned", //946
					"Unassigned", //947
					"Unassigned", //948
					"Unassigned", //949
					"Unassigned", //950
					"Unassigned", //951
					"Unassigned", //952
					"Unassigned", //953
					"Unassigned", //954
					"Unassigned", //955
					"Unassigned", //956
					"Unassigned", //957
					"Unassigned", //958
					"Unassigned", //959
					"Unassigned", //960
					"Unassigned", //961
					"Unassigned", //962
					"Unassigned", //963
					"Unassigned", //964
					"Unassigned", //965
					"Unassigned", //966
					"Unassigned", //967
					"Unassigned", //968
					"Unassigned", //969
					"Unassigned", //970
					"Unassigned", //971
					"Unassigned", //972
					"Unassigned", //973
					"Unassigned", //974
					"Unassigned", //975
					"Unassigned", //976
					"Unassigned", //977
					"Unassigned", //978
					"Unassigned", //979
					"Unassigned", //980
					"Unassigned", //981
					"Unassigned", //982
					"Unassigned", //983
					"Unassigned", //984
					"Unassigned", //985
					"Unassigned", //986
					"Unassigned", //987
					"Unassigned", //988
					"ftps-data", //989
					"ftps", //990
					"nas", //991
					"telnets", //992
					"imaps", //993
					"Reserved", //994
					"pop3s", //995
					"vsinet", //996
					"maitrd", //997
					"busboy (TCP); puparp (UDP)", //998
					"garcon/puprouter (TCP); applix/puprouter (UDP)", //999
					"cadlock2", //1000
					"Unassigned", //1001
					"Unassigned", //1002
					"Unassigned", //1003
					"Unassigned", //1004
					"Unassigned", //1005
					"Unassigned", //1006
					"Unassigned", //1007
					"Unassigned", //1008
					"Unassigned", //1009
					"surf", //1010
					"Reserved", //1011
					"Reserved", //1012
					"Reserved", //1013
					"Reserved", //1014
					"Reserved", //1015
					"Reserved", //1016
					"Reserved", //1017
					"Reserved", //1018
					"Reserved", //1019
					"Reserved", //1020
					"exp1", //1021
					"exp2", //1022
					"Reserved", //1023
					"Reserved" //1024
					};
extern int scan;
extern int version_flag;
extern int no_of_jobs;					
extern int job_index;					
extern int no_of_threads;
extern int no_of_scans;
extern struct job_queue ** job_q;
extern pthread_mutex_t mymutex;
extern struct result_table ** result_t;
extern int syn_flag, ack_flag, xmas_flag, null_flag, fin_flag, udp_flag;
extern unsigned char ** ip_list;
void dummy_func(int temp)
{
	printf("\nThis is  a dummy function   Temp = %d\n", temp);

}
/***************************
 * For parsing arguments 
 *
 * *************************/
unsigned int ** parse_args(int argc, char** argv, ps_args_t* object, unsigned char** ip_list, unsigned int** port_list)
{
	  
    int i = 0;
    int ip_count = 0;
    int port_flag = 0;
    no_of_threads = 1;		/* By default 1 thread	*/
    int scan_flag = 0;  
    memset(object->filename, 0, FILE_NAME_MAX);
    for (i = 0 ; i<6; i++)	{
	memset(service_version[i],0,30);
	strncpy(service_version[i],"NUL", strlen("NUL"));    
    }
	
    while (1) 
    {   
      static struct option long_options[] =
        {   
          {"help",    no_argument,0, 'a'},
          {"ports",   required_argument, 0, 'b'},
          {"ip",      required_argument, 0, 'c'},
          {"prefix",  required_argument, 0, 'd'},
          {"file",    required_argument, 0, 'e'},
          {"speedup", required_argument, 0, 'f'},
          {"scan",    required_argument, 0, 'g'},    // scan can have multiple args. So dont make it a : bound to scan optarg
          {0, 0, 0, 0}
        };  
      /* getopt_long stores the option index here. */
      int option_index = 0;

      i = getopt_long (argc, argv, "ab:c:d:e:f:g:",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (i == -1) 
        break;

      switch (i) 
        {   
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'a':	/* help */
	  print_help();
	  exit(0);
          break;

        case 'b':	/* Ports */
	  port_list = parse_ports(optarg, port_list, object);
	  port_flag = 1;
	  break;

        case 'c':	/* IP */
          if(gethostbyname(optarg) ==  NULL){
    		printf("ERROR:gethostbyname failure, no such host\n");
    		exit(1);
	  }
	  ip_list[ip_count] = (unsigned char *) malloc (strlen(optarg)+1);
	  memset(ip_list[ip_count],0,strlen(optarg)+1);
	  strncpy((char*)ip_list[ip_count], optarg, strlen(optarg)+1);
	  ip_count++;
	  break;

        case 'd':	/* prefix */
          ip_count = parse_prefix(ip_count,optarg, ip_list);
	  break;

       case 'e':	/* filename */
	  strncpy(object->filename, optarg, FILE_NAME_MAX);          
	  ip_count = read_ip_from_file(ip_count, object->filename, ip_list);
          break;

        case 'f':	/* speedup */
          no_of_threads = atoi(optarg);
	  break;

        case 'g':	/* scan */
        scan_flag = 1;  
	if (strcmp(optarg, "SYN") == 0)	{
		scan = SYN;
		syn_flag = 1;
		no_of_scans++;  
	}
          else if (strcmp(optarg, "NULL") == 0)	{
		scan = NUL;
		null_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(optarg, "FIN") == 0)	{
		scan = FIN;
		fin_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(optarg, "XMAS") == 0)	{
		scan = XMAS;
		xmas_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(optarg, "ACK") == 0) 	{
		scan = ACK;
		ack_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(optarg, "UDP") == 0)	{
		scan = UDP;
		udp_flag = 1;
		no_of_scans++;  
	  }
	  else	{ 
	  	print_help(); 
          	exit(1);
	  }
	int z = 0;
	int opt_index = optind;	
	for (z = 0; z<5; z++)	{

	if (opt_index >= argc)	
		break;
	opt_index++;
          if (strcmp(argv[optind+z], "SYN") == 0)	{
		scan = SYN;
		syn_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(argv[optind+z], "NULL") == 0)	{
		scan = NUL;
		null_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(argv[optind+z], "FIN") == 0)	{
		scan = FIN;
		fin_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(argv[optind+z], "XMAS") == 0)	{
		scan = XMAS;
		xmas_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(argv[optind+z], "ACK") == 0) 	{
		scan = ACK;
		ack_flag = 1;
		no_of_scans++;  
	  }
          else if (strcmp(argv[optind+z], "UDP") == 0)	{
		scan = UDP;
		udp_flag = 1;
		no_of_scans++;  
	  }
	  else	 
		break;  
		
	}
	  break;

        default:
          printf("\nERROR: Invalid option\n");
	  print_help(); 
          exit(1);
        }
    }



	if (argc > 14 || argc == 1)	{
		printf("\nERROR: Invalid no. of arguments\n");
		print_help();
		exit(1);
	}

	int flag = 0;	
	if (ip_count == 0)	{
		/* Check for stray IPs present in the command line */
		for (i=1; i<argc; i++)	{
          		if(gethostbyname(argv[i]) !=  NULL && (strlen((argv[i])) >= MIN_IP_LEN)){	/*  minimum strlen of 1.1.1.1 is 7*/
	  			flag = 1;
	  			ip_list[ip_count] = (unsigned char *) malloc (strlen(argv[i])+1);
	  			memset(ip_list[ip_count],0,strlen(argv[i])+1);
	  			strncpy((char*)ip_list[ip_count], argv[i], strlen(argv[i])+1);
	  			ip_count++;
			}
			
		}
		/* If no stray IP is found */
		if (flag != 1 && flag == 0)	{
			printf("\nERROR: No valid IPs found\n");
			print_help();
			exit(1);
		}
	}

	if (strcmp("--help", object->filename) == 0)	{
		print_help();
		exit(1);
	}
	
	object->total_ip_count = ip_count;

	if (port_flag !=1) {
		port_list = parse_ports("1-1024", port_list, object);
		object->total_port_count = 1024;
		
	}
	if(scan_flag == 0)	{	/* All scans by default */
		syn_flag =1;
		fin_flag =1;
		xmas_flag =1;
		null_flag =1;
		ack_flag =1;
		udp_flag =1;
		no_of_scans = 6;
	}
	return port_list;
}
/*****************************
 * Reading ip from file
 * **************************/
int read_ip_from_file(int ip_count, char * filename, unsigned char ** ip_list)
{
	FILE * fp = NULL;
	char * line = (char*) malloc (size_of_IP);
	memset(line,0,size_of_IP);
	size_t len = 0;
        ssize_t read;
	fp = fopen(filename,"r");
	if (fp == NULL)	{
		printf("ERROR: Unable to open file containing IP list\n");
    		free(line);
		exit(1);
	}	
	while ((read = getline(&line, &len, fp)) != -1) {
		line[strlen(line)-1] = '\0';
          	if(gethostbyname(line) ==  NULL){
    			printf("ERROR:gethostbyname failure, while reading IP list from file\n");
    			free(line);
			exit(1);
	  	}
		ip_list[ip_count] = (unsigned char *) malloc (strlen(line)+1);
	  	strncpy((char*)ip_list[ip_count], line, strlen(line)+1);
		ip_count++;
	}



	fclose(fp);
	free(line);
	return ip_count;
}
/****************************
 * Parsing ports
 * **************************/
unsigned int ** parse_ports(char * port_string, unsigned int ** port_list, ps_args_t* object)
{
	
	char * parse_str = NULL;
	char * word = NULL;
	char sep[] = ",";
	parse_str = malloc(strlen(port_string)+1);
  	strncpy(parse_str, port_string, strlen(port_string)+1);
	
	int i = 0;
	int comma_count = 0;
	int hiphen_count = 0;
    	char port_array[ROW][COL];
	
	for ( i=0 ; i<ROW; i++ )
		memset(port_array[i],0,COL);

	for (i=0; port_string[i] != '\0'; i++) {
		if (port_string[i] == ',')
			comma_count++;
		else if (port_string[i] == '-')
			hiphen_count++;
	}
		
  	for(word = strtok(parse_str, sep), i=0; (word && i <=comma_count); word = strtok(NULL,sep), i++){
	
		strncpy(port_array[i], word, strlen(word)+1);	

	}

	printf("\n");	
	i=0;
	int j=0;
	int k=0;
	int count = 0;
	int port_range[2];
	int port_total = 0;
	char sep1[] = "-";
	free(parse_str);
		
	while (strlen(port_array[i]) > 0)	{

			/* elemnts without '-'*/	
		if (strstr(port_array[i], "-") == NULL)	{
			port_list = (unsigned int**) realloc (port_list, (count+1)*sizeof(unsigned int*));
			port_list[count] = (unsigned int*) malloc (sizeof(unsigned int));
			*(port_list[count]) = atoi(port_array[i]);
			count++;
				
		}
			/* elements with '-' */
		else	{
			k=0;
			parse_str = NULL;
			word = NULL;
			parse_str = malloc(strlen(port_array[i])+1);
  			strncpy(parse_str, port_array[i], strlen(port_array[i])+1);
			
  			for(word = strtok(parse_str, sep1), k=0; (word && k <2); word = strtok(NULL,sep1), k++){
				port_range[k] = atoi(word);
			}
			
			port_total = port_range[1] - port_range[0] + 1;	
			port_list = (unsigned int**) realloc (port_list, (count+port_total+1)*sizeof(unsigned int*));
			
			for (j = port_range[0]; j<=port_range[1]; j++)	{
				port_list[count] = (unsigned int*) malloc (sizeof(unsigned int));
				*(port_list[count]) = j;
				count++;
			}			
			free(parse_str);
		}
		i++;
	}

	i=0;
	while ( i<count)	{
		i++;
	}

	object->total_port_count = count;
	return port_list;
	
}

/****************************
 * Parsing Prefix
 * **************************/
int parse_prefix(int ip_count, char * prefix, unsigned char ** ip_list)
{
	char * parse_str = NULL;
	char * word = NULL;
	char * ip = NULL;
	int cidr = 0;
	char sep[] = "/";
	int i = 0;
	char line[size_of_IP];
	memset(line,0,size_of_IP);

	parse_str = malloc(strlen(prefix)+1);
  	strncpy(parse_str, prefix, strlen(prefix)+1);

  	for(word = strtok(parse_str, sep), i=0; (word && i < 3); word = strtok(NULL,sep), i++){

    	switch(i){
    		case 0:
      			ip = word;
      			break;
    		case 1:
      			cidr = atoi(word);
    		default:
      			break;
    		}

  	}

          if(gethostbyname(ip) ==  NULL){
    		printf("ERROR:gethostbyname failure in prefix\n");
    		exit(1);
	  }


	if (cidr > 31 || cidr < 1) {
		free(parse_str);
		printf("ERROR: Invalid Prefix\n");
		exit(1);
	}	


  	if(i < 2){
    		fprintf(stderr,"ERROR: Parsing Prefix: Not enough values in '%s'\n",prefix);
    		print_help();
		free(parse_str);
    		exit(1);
  	}

  	if(word){
    		fprintf(stderr, "ERROR: Parsing Prefix: Too many values in '%s'\n",prefix);
  		print_help();
		free(parse_str);
    		exit(1);
  	}

	struct in_addr address_struct_new;
	struct in_addr address_struct_new1;
	struct in_addr in;
	
	in_addr_t net, brod, address;
	inet_aton(ip, &in);

	address = (ntohl(in.s_addr) & (~((1 << (32 - cidr)) - 1))); /*  Network Address = Ip address & (Subnet Mask)*/
  
	net = ntohl(address);
	address_struct_new.s_addr = net;

	brod = (address | ~(~((1 << (32 - cidr)) - 1)));	/* Broadcasr address = Ip address | (~Subnet Mask)*/
	brod = ntohl(brod);
	address_struct_new1.s_addr = brod;

  	net = address;

	brod = inet_addr(inet_ntoa(address_struct_new1));
	net = inet_addr(inet_ntoa(address_struct_new));
	do
	{
		strncpy(line, inet_ntoa(address_struct_new), strlen(inet_ntoa(address_struct_new)));	
		ip_list[ip_count] = (unsigned char *) malloc (strlen(line)+1);
	  	strncpy((char*)ip_list[ip_count], line, strlen(line)+1);
		memset(line,0,size_of_IP);
		ip_count++;
         	net = ntohl(net);
             	net += 1;
                net = htonl(net);
             	address_struct_new.s_addr = net;
	
		/* Adding all the ips to the main list of IP addresses */
		
	}	
	while (net <  brod);
		/* for the last address ie broadcast address */
		strncpy(line, inet_ntoa(address_struct_new), strlen(inet_ntoa(address_struct_new)));	
		ip_list[ip_count] = (unsigned char *) malloc (strlen(line)+1);
	  	strncpy((char*)ip_list[ip_count], line, strlen(line)+1);
		memset(line,0,size_of_IP);
		ip_count++;
         	net = ntohl(net);
             	net += 1;
                net = htonl(net);
             	address_struct_new.s_addr = net;

	free(parse_str);
	return ip_count;
}
/*************************
 * Help menu
 * **********************/
void print_help()
{
	fprintf(stdout,
          "./portScanner [Option1, Option2, ......, OptionN]\n"
          "  --help        				\t Eg: ./portScanner --help\n"
          "  --ports <ports to scan>        		\t Eg: ./portScanner --ports 1,2,3-5\n"
          "  --ip <IP address to scan>    	   		\t Eg: ./portScanner --ip 127.0.0.1\n"
          "  --prefix <IP prefix to scan>        		\t Eg: ./portScanner --prefix 127.143.151.123/24\n"
          "  --file <file name containing IP addresses to scan> \t Eg: ./portScanner --file filename.txt\n"
          "  --speedup <parallel threads to use>        	\t Eg: ./portScanner --speedup 10\n"
          "  --scan <one or more scans>       		\t Eg: ./portScanner --scan SYN NULL FIN XMAS\n");
}
/************************
 * Checksum function
 * **********************/
unsigned short csum_new(unsigned short *ptr,int nbytes)
{

        unsigned int sum = 0;           /* 4 bytes  (32 bit)   stores with carryover */
        int i =0;
        for ( i=0; i<(nbytes/2); i++) {
                sum = sum + *ptr;
                ptr++;
        }
        unsigned short *temp1 = (unsigned short*) &sum;
        unsigned short *temp2 = (unsigned short*) &sum;
        temp2++;
        sum = *temp1 + *temp2;

        while (*temp2 != 0)     {
                sum = *temp1 + *temp2;
        }
        return ~(*temp1);
}
/************************
 * Finding nic address
 * *********************/
int get_nic_addr(char * source_ip)
{
struct ifaddrs *nic_addr;
struct ifaddrs *nic_ptr;
int family = 0;
int ret = 0;
int  i = 0;
char host_ip[NI_MAXHOST];

        if (getifaddrs(&nic_addr) == -1) {
                perror("getifaddrs");
                return -1;
        }

        for (i=0, nic_ptr = nic_addr; nic_ptr != NULL; nic_ptr = nic_ptr->ifa_next, i++) {
                if (nic_ptr->ifa_addr == NULL)
                        continue;

                family = nic_ptr->ifa_addr->sa_family;
                if (strcmp(nic_ptr->ifa_name, "eth0") == 0){
                        if (family == AF_INET) {
                                ret = getnameinfo(nic_ptr->ifa_addr,
                                                        sizeof(struct sockaddr_in),
                                                        host_ip, NI_MAXHOST,
                                                        NULL, 0, NI_NUMERICHOST);
                        if (ret != 0) {
                                printf("getnameinfo() not successfull\n");
                                return -1;
				exit(1);
                        } 
                        strncpy(source_ip, host_ip, strlen(host_ip));
			}
                }
        }

        freeifaddrs(nic_addr);
	return 1;
}
/****************************************
 * changing format function for dns query
 * ***************************************/
void changeHostFormat(unsigned char* dns,unsigned char* host)
{

dns[0] = (unsigned char)3; 
dns[1] = 'w'; 
dns[2] = 'w'; 
dns[3] = 'w'; 
dns[4] = (unsigned char)6; 
dns[5] = 'g'; 
dns[6] = 'o'; 
dns[7] = 'o'; 
dns[8] = 'g'; 
dns[9] = 'l'; 
dns[10] = 'e'; 
dns[11] = (unsigned char)3;
dns[12] = 'c'; 
dns[13] = 'o'; 
dns[14] = 'm'; 
dns[15] = '\0';

}
/******************************************
 * Service Version for dagwood open ports
 * ****************************************/
void ServiceVersion(int port, char * d_ip, char * version)
{

struct  sockaddr_in sin_addr;
char ver_sub[30];
char buffer[1024];
sin_addr.sin_port = htons(port);
sin_addr.sin_addr.s_addr = inet_addr(d_ip);
sin_addr.sin_family = AF_INET;
memset(ver_sub,0,30);
char * ptr1 = NULL;
char * ptr2 = NULL;
        int sock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        if (sock_fd <0)
                printf("\nSocket creation failed (For get version)\n");

        int ret = connect(sock_fd,(struct sockaddr*)&sin_addr,sizeof(sin_addr));
        if (ret <0)
                printf("\nConnect failed (For get version)\n");

        if(port==80){
                if((send(sock_fd,"GET/HTTP/1.1\r\n\r\n",25,0))>0){

                }
                else
                        printf("\nSend failed for http version number\n");
        }
        else if(port==110){
                if((send(sock_fd,"ABCD",22,0))>0){
                }
                else
                        printf("\nSend failed for POP3 version number\n");

        }
        memset(buffer, 0, 1024);

        if ((recv(sock_fd,buffer,1024,0)) > 0){
                close(sock_fd);
        }


        if (port == 22) {
                ptr1 = strstr(buffer, "_");
                ptr1 +=1;
                ptr2 = ptr1;
                ptr2 = strstr(ptr2, "\n");
                int diff = ptr2-ptr1;
                strncpy(version,ptr1,diff-1);
                strcat(version, " Protocol ");
                ptr1 = strstr(buffer, "-");
                ptr1 +=1;
                ptr2 = ptr1;
                ptr2 = strstr(ptr2, "-");
                diff = ptr2-ptr1;
                strncpy(ver_sub,ptr1,diff);
                strcat(version, ver_sub);

        }

        else if (port == 24)    {
                ptr1 = strstr(buffer, "beta");
                ptr1 +=5;
                ptr2 = ptr1;
                ptr2 = strstr(ptr2, ";");
                int diff = ptr2-ptr1;
                strncpy(version,ptr1,diff);
        }

        else if (port == 43)    {
                ptr1 = strstr(buffer, "Version");
                ptr1 +=8;
                ptr2 = ptr1;
                ptr2 = strstr(ptr2, "\n");
                int diff = ptr2-ptr1;
                strncpy(version,ptr1,diff);

        }

        else if (port == 80)    {
                ptr1 = strstr(buffer, "address");
                ptr1 +=8;
                ptr2 = ptr1;
                ptr2 = strstr(ptr2, " ");
                int diff = ptr2-ptr1;
                strncpy(version,ptr1,diff);

        }

        else if (port == 110)   {
                ptr1 = strstr(buffer, " ");
                ptr1 +=1;
                ptr2 = ptr1;
                ptr2 = strstr(ptr2, " ");
                int diff = ptr2-ptr1;
                strncpy(version,ptr1,diff);

        }

        else if (port == 143)   {
                ptr1 = strstr(buffer, "CAPABILITY");
                ptr1 +=11;
                ptr2 = ptr1;
                ptr2 = strstr(ptr2, " ");
                int diff = ptr2-ptr1;
                strncpy(version,ptr1,diff);
                ptr1 = strstr(buffer, "]");
                ptr1+=2;
                ptr2 = ptr1;
                ptr2 = strstr(ptr2, " ");
                diff = ptr2-ptr1+1;
                ptr1--;
                strncpy(ver_sub,ptr1,diff);
                strcat(version,ver_sub);
        }
}
/*************************************
 * Filling the result data structure
 * ***********************************/
void populateConclusionTable(int result_count, int port_count)
{
	int i =0;
	int r_index = 0;
	
	/* initialisation */
	for (i=0; i<result_count;i++)	{
		memset(result_t[i]->r_ip, 0,32);
		memset(result_t[i]->r_service, 0,50);
		result_t[i]->r_port = 0;	
		memset(result_t[i]->r_version, 0,30);
		memset(result_t[i]->r_syn, 0,32);
		memset(result_t[i]->r_fin, 0,32);
		memset(result_t[i]->r_null, 0,32);
		memset(result_t[i]->r_xmas, 0,32);
		memset(result_t[i]->r_ack, 0,32);
		memset(result_t[i]->r_udp, 0,32);
		memset(result_t[i]->r_conclusion, 0,32);
	}



	/*	this loop is meant for one entry in the result table	*/	
	int j =0;
	for (i=0; i<no_of_jobs; i+=no_of_scans)	{
		j=0;
		strncpy(result_t[r_index]->r_ip,job_q[i]->q_ip, strlen(job_q[i]->q_ip));	
		if (job_q[i]->q_port >=1 && job_q[i]->q_port <=1024)
			strncpy(result_t[r_index]->r_service, service_name[job_q[i]->q_port -1], strlen(service_name[job_q[i]->q_port -1]) );		
		else
			strncpy(result_t[r_index]->r_service, "N/A", strlen("N/A") );		
		result_t[r_index]->r_port = job_q[i]->q_port;

		if (strcmp(job_q[i]->q_ip,"129.79.247.87") == 0 && (job_q[i]->q_port == 22 || job_q[i]->q_port == 24 || job_q[i]->q_port == 43 || 
				job_q[i]->q_port == 80 || job_q[i]->q_port == 110 || job_q[i]->q_port == 143))
			
			switch(job_q[i]->q_port)	{
				case 22:	strncpy(result_t[r_index]->r_version,service_version[0],strlen(service_version[0]));
						break;
				case 24:	strncpy(result_t[r_index]->r_version,service_version[1],strlen(service_version[1]));
						break;
				case 43:	strncpy(result_t[r_index]->r_version,service_version[2],strlen(service_version[2]));
						break;
				case 80:	strncpy(result_t[r_index]->r_version,service_version[3],strlen(service_version[3]));
						break;
				case 110:	strncpy(result_t[r_index]->r_version,service_version[4],strlen(service_version[4]));
						break;
				case 143:	strncpy(result_t[r_index]->r_version,service_version[5],strlen(service_version[5]));
						break;
				
			}
			
		while (j<no_of_scans)	{	
			if (job_q[j+i]->q_scan == SYN)	
				strncpy(result_t[r_index]->r_syn,job_q[j+i]->q_result,strlen(job_q[j+i]->q_result));
			else if(job_q[j+i]->q_scan == FIN)
				strncpy(result_t[r_index]->r_fin,job_q[j+i]->q_result,strlen(job_q[j+i]->q_result));
			else if(job_q[j+i]->q_scan == NUL)
				strncpy(result_t[r_index]->r_null,job_q[j+i]->q_result,strlen(job_q[j+i]->q_result));
			else if(job_q[j+i]->q_scan == XMAS)
				strncpy(result_t[r_index]->r_xmas,job_q[j+i]->q_result,strlen(job_q[j+i]->q_result));
			else if(job_q[j+i]->q_scan == ACK)
				strncpy(result_t[r_index]->r_ack,job_q[j+i]->q_result,strlen(job_q[j+i]->q_result));
			else if(job_q[j+i]->q_scan == UDP)
				strncpy(result_t[r_index]->r_udp,job_q[j+i]->q_result,strlen(job_q[j+i]->q_result));
		
		j++;	
		}
		/*********	Final Port Status Logic *************/
		/****************************************************/	
		if(strcmp(result_t[r_index]->r_syn,"SYN(Open)")==0 || strcmp(result_t[r_index]->r_udp,"UDP(Open)")==0)	{
			strncpy(result_t[r_index]->r_conclusion, "Open", strlen("Open"));	
		}
		else if(strcmp(result_t[r_index]->r_syn,"SYN(Closed)")==0 || strcmp(result_t[r_index]->r_udp,"UDP(Closed)")==0)	{
			strncpy(result_t[r_index]->r_conclusion, "Closed", strlen("Closed"));	
		}
		/* added */	
		else if(strcmp(result_t[r_index]->r_syn,"SYN(Filtered)")==0 && (strcmp(result_t[r_index]->r_fin,"FIN(Closed)")==0 || 
			strcmp(result_t[r_index]->r_xmas,"XMAS(Closed)")==0  || strcmp(result_t[r_index]->r_null,"NULL(Closed)")==0    ))	{
			strncpy(result_t[r_index]->r_conclusion, "Closed", strlen("Closed"));	
		}

		else if(strcmp(result_t[r_index]->r_syn,"SYN(Filtered)")==0 && strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0)	{
			strncpy(result_t[r_index]->r_conclusion, "Unfiltered", strlen("Unfiltered"));	
		}
		else if(strcmp(result_t[r_index]->r_syn,"SYN(Filtered)")==0)	{
			strncpy(result_t[r_index]->r_conclusion, "Filtered", strlen("Filtered"));	
		}
		else if((strcmp(result_t[r_index]->r_udp,"UDP(Open|Filtered)")==0) && ((strcmp(result_t[r_index]->r_fin,"FIN(Closed)")==0)	||
				(strcmp(result_t[r_index]->r_null,"NULL(Closed)")==0) || (strcmp(result_t[r_index]->r_xmas,"XMAS(Closed)")==0)) )	{
			strncpy(result_t[r_index]->r_conclusion, "Closed", strlen("Closed"));	
		}
		else if((strcmp(result_t[r_index]->r_fin,"FIN(Closed)")==0)	||
				(strcmp(result_t[r_index]->r_null,"NULL(Closed)")==0) || (strcmp(result_t[r_index]->r_xmas,"XMAS(Closed)")==0)) 	{
			strncpy(result_t[r_index]->r_conclusion, "Closed", strlen("Closed"));	
		}
		else if((strcmp(result_t[r_index]->r_fin,"FIN(Filtered)")==0)	||
				(strcmp(result_t[r_index]->r_null,"NULL(Filtered)")==0) || (strcmp(result_t[r_index]->r_xmas,"XMAS(Filtered)")==0)) 	{
			strncpy(result_t[r_index]->r_conclusion, "Filtered", strlen("Filtered"));	
		}
		else if((strcmp(result_t[r_index]->r_udp,"UDP(Open)")==0)	&&
				((strcmp(result_t[r_index]->r_ack,"ACK(Filtered)")==0) || (strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0))) 	{
			strncpy(result_t[r_index]->r_conclusion, "Open", strlen("Open"));	
		}
		else if((strcmp(result_t[r_index]->r_udp,"UDP(Closed)")==0)	&&
				((strcmp(result_t[r_index]->r_ack,"ACK(Filtered)")==0) || (strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0))) 	{
			strncpy(result_t[r_index]->r_conclusion, "Closed", strlen("Closed"));	
		}
		else if(((strcmp(result_t[r_index]->r_udp,"UDP(Open|Filtered)")==0) && (strcmp(result_t[r_index]->r_ack,"ACK(Filtered)")==0)) ||
				((strcmp(result_t[r_index]->r_udp,"UDP(Filtered)")==0) && (strcmp(result_t[r_index]->r_ack,"ACK(Filtered)")==0))) 	{
			strncpy(result_t[r_index]->r_conclusion, "Filtered", strlen("Filtered"));	
		}
		else if(((strcmp(result_t[r_index]->r_udp,"UDP(Open|Filtered)")==0) && (strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0)) ||
				((strcmp(result_t[r_index]->r_udp,"UDP(Filtered)")==0) && (strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0))) 	{
			strncpy(result_t[r_index]->r_conclusion, "Unfiltered", strlen("Unfiltered"));	
		}
		
		else if((strcmp(result_t[r_index]->r_fin,"FIN(Closed)")==0 ||	(strcmp(result_t[r_index]->r_null,"NULL(Closed)")==0) || 
			(strcmp(result_t[r_index]->r_xmas,"XMAS(Closed)")==0)) &&
				((strcmp(result_t[r_index]->r_ack,"ACK(Filtered)")==0) || (strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0))) 	{
			strncpy(result_t[r_index]->r_conclusion, "Closed", strlen("Closed"));	
		}
		else if(((strcmp(result_t[r_index]->r_fin,"FIN(Open|Filtered)")==0 || strcmp(result_t[r_index]->r_xmas,"XMAS(Open|Filtered)")==0 ||
			strcmp(result_t[r_index]->r_null,"NULL(Open|Filtered)")==0 )&& (strcmp(result_t[r_index]->r_ack,"ACK(Filtered)")==0)) ||
				((strcmp(result_t[r_index]->r_fin,"FIN(Filtered)")==0 || strcmp(result_t[r_index]->r_xmas,"XMAS(Filtered)")==0 ||                        
				strcmp(result_t[r_index]->r_null,"NULL(Filtered)")==0 )&& (strcmp(result_t[r_index]->r_ack,"ACK(Filtered)")==0) )) 	{
			strncpy(result_t[r_index]->r_conclusion, "Filtered", strlen("Filtered"));	
		}
		else if(((strcmp(result_t[r_index]->r_fin,"FIN(Open|Filtered)")==0 || strcmp(result_t[r_index]->r_xmas,"XMAS(Open|Filtered)")==0 ||
			strcmp(result_t[r_index]->r_null,"NULL(Open|Filtered)")==0 )&& (strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0)) ||
				((strcmp(result_t[r_index]->r_fin,"FIN(Filtered)")==0 || strcmp(result_t[r_index]->r_xmas,"XMAS(Filtered)")==0 ||                        
				strcmp(result_t[r_index]->r_null,"NULL(Filtered)")==0 )&& (strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0) )) 	{
			strncpy(result_t[r_index]->r_conclusion, "Unfiltered", strlen("Unfiltered"));	
		}
		else if((strcmp(result_t[r_index]->r_ack,"ACK(Filtered)")==0)) 	{
			strncpy(result_t[r_index]->r_conclusion, "Filtered", strlen("Filtered"));	
		}
		else if((strcmp(result_t[r_index]->r_ack,"ACK(Unfiltered)")==0)) {
			strncpy(result_t[r_index]->r_conclusion, "Unfiltered", strlen("Unfiltered"));	
		}
		
		else {
			strncpy(result_t[r_index]->r_conclusion, "Open|Filtered", strlen("Open|Filtered"));	
		}
		
		r_index++;
	}
		printf("IP");
		printf("\t\tPort");
		printf("\t\tService");
		
		
		printf("\t\t\t\t\t\tIndividual Results and Conclusion");
			printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");	
		printf("\n");	
	/* Also printing the final output here */	
	for (i=0; i<result_count; i++)	{
		printf("%-16s ",result_t[i]->r_ip);
		printf("%-6d  ",result_t[i]->r_port);
		printf("%-35s",result_t[i]->r_service);
		if(syn_flag == 1)
			printf("%-15s",result_t[i]->r_syn);
		if(fin_flag == 1)
			printf("%-20s",result_t[i]->r_fin);
		if(null_flag == 1)
			printf("%-22s",result_t[i]->r_null);
		if(xmas_flag == 1)
			printf("%-20s",result_t[i]->r_xmas);
		if(ack_flag == 1)
			printf("%-17s",result_t[i]->r_ack);
		if(udp_flag ==1)
			printf("%-20s",result_t[i]->r_udp);
			
		
		printf("%-10s", result_t[i]->r_conclusion);
		
		if (strcmp(result_t[i]->r_ip,"129.79.247.87") == 0 && ( result_t[i]->r_port == 22 || result_t[i]->r_port == 24 || result_t[i]->r_port == 43 || 
				result_t[i]->r_port == 80 ||result_t[i]->r_port == 110 || result_t[i]->r_port  == 143) && (strcmp(result_t[i]->r_conclusion,"Open")==0)  )
		printf("%-15s", result_t[i]->r_version);
		
		if((i+1)%port_count==0)
			printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");	
		printf("\n");	
	}
}

/*==============================*/
/*	Thread Function		*/
/*==============================*/
void * my_function(void * arg)
{
while(1)
{
int j =0;
        pthread_mutex_lock(&mymutex);
                j=job_index;					/* Finding current global job index for jobs in message queue	*/
         	printf(".");
		fflush(stdout);
                if (j>no_of_jobs-1)	{
			pthread_mutex_unlock(&mymutex);
                        return NULL;
                }	
		j=j+1;
                job_index=j;
	pthread_mutex_unlock(&mymutex);
	
	if (no_of_threads > 1)
		sleep(0.5);

	if (job_q[j-1]->q_scan == UDP && job_q[j-1]->q_port != 53)	{	/*   	IF START UDP SCAN BLOCK 		*/

char datagram[4096];
char result[32];
char source_ip[32];
struct iphdr *iph = (struct iphdr *) datagram;
struct udphdr *udph = (struct udphdr *) (datagram + sizeof (struct iphdr));	
struct sockaddr_in sin_addr;
	/* Nic Address */
	memset(source_ip, 0, 32);
	int ret_val = get_nic_addr(source_ip);
	if (ret_val == -1)	{
		perror("getifaddrs");
		exit(1);
	}
unsigned char buffer[BUFFER_SIZE];
memset(buffer,0,BUFFER_SIZE);
int data_size = 0;
socklen_t ssize = sizeof(sin_addr);
 
	/*   Create a raw socket	*/
    int s = socket (PF_INET, SOCK_RAW, IPPROTO_UDP);    
    if(s == -1)
    {
        perror("Failed to create socket");
        exit(1);
    }
     
    memset (datagram, 0, 4096);
    sin_addr.sin_family = AF_INET;
    sin_addr.sin_port = htons(job_q[j-1]->q_port);
    sin_addr.sin_addr.s_addr = inet_addr (job_q[j-1]->q_ip);
     
    /* Fill in the IP Header */
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;
    iph->tot_len = sizeof (struct iphdr) + sizeof (struct udphdr); 
    iph->id = htonl (54321); 
    iph->frag_off = 0;
    iph->ttl = 255;
    iph->protocol = IPPROTO_UDP;
    iph->check = 0;      
    iph->saddr = inet_addr ( source_ip ); 
    iph->daddr = sin_addr.sin_addr.s_addr;
    iph->check = csum_new ((unsigned short *) datagram, sizeof (struct iphdr));
   
    /* Fill in the UDP Header */
    int r = 0;
    r = 2000 + (rand() % (5000));
    udph->source = htons (r);
    udph->dest = htons (job_q[j-1]->q_port);
    udph->len = htons(sizeof(struct udphdr));
    udph->check = 0; 
	    
 
    int one = 1;
    const int *val = &one;
     
    if (setsockopt (s, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) < 0)
    {
        perror("Error IP_HDRINCL");
        exit(0);
    }
    int x=0;
    int flag = 0;
 	
    while (x<3)		/* For 3 retransmissions */
    {
        if (sendto (s, datagram, iph->tot_len ,  0, (struct sockaddr *) &sin_addr, sizeof (sin_addr)) < 0)		/* Send UDP */
        {
            perror("sendto failed");
        }
struct timeval  tv3, tv4;
double time_spent;
int new_flag = 0;
memset(job_q[j-1]->q_result, 0, 32);
memset(result, 0, 32);
memset(buffer, 0, BUFFER_SIZE);
while ((data_size = recvfrom(s , buffer , BUFFER_SIZE , 0 , (struct sockaddr *) &sin_addr, &ssize)) > 0)		/* Recv UDP */
       {
    new_flag = 0;
    struct iphdr *iph_r = (struct iphdr*)buffer;
    struct sockaddr_in source,dest;
    unsigned short iphdrlen;
    iphdrlen = iph_r->ihl*4;
    struct udphdr *tcph_r=(struct udphdr*)(buffer + iphdrlen);
    
	if(iph_r->protocol == 17 )	{		/* UDP = 17 */
             
        memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = iph_r->saddr;
     
        memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = iph_r->daddr;
         
       		if(iph_r->saddr == iph->daddr && iph_r->daddr == iph->saddr && tcph_r->source == udph->dest && tcph_r->dest == udph->source)
		{	
	    		strncpy(result, "UDP(Open)", strlen("UDP(Open)"));
			new_flag = 1;
		}

	}

   	        if ( new_flag ==1 )	{
			flag = 1;
			break;
		}
   	       else if( new_flag == 0 )	{
				gettimeofday(&tv3, NULL);
			while(1) {
				gettimeofday(&tv4, NULL);
         			time_spent = (double) (tv4.tv_sec - tv3.tv_sec);
        				if (time_spent>=3.0)	{
            					break;
					}
			}
        		if (time_spent>=3.0)	{
				break;
			}
		}	
			
       }	/*  Recv from while end */
      

	if(data_size <0 )
        {
            printf("Recvfrom error occurred, failed to get any packets\n");
            fflush(stdout);
        }
	else if (flag == 1)
		break;
		/* Now sending via icmp sockets to try and get some icmp reply */
int icmp_retransmit = 0;
	if (x == 2 && job_q[j-1]->q_scan == UDP)	{		//1 = syn
		icmp_retransmit = 0;
            	close(s);	
		int sock_icmp = socket (PF_INET, SOCK_RAW, IPPROTO_ICMP);    
    		if (setsockopt (sock_icmp, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) < 0)
    		{
        		perror("Error IP_HDRINCL");
        		exit(0);
    		}

        	if (sendto (sock_icmp, datagram, iph->tot_len ,  0, (struct sockaddr *) &sin_addr, sizeof (sin_addr)) < 0)		
            		perror("sendto failed");
			
			memset(buffer,0,BUFFER_SIZE);
			fd_set readfds;
			struct timeval tv;
			FD_ZERO(&readfds);
			FD_SET(sock_icmp, &readfds);
			int n = sock_icmp + 1;
			tv.tv_sec = 2;
			tv.tv_usec = 0;
			int rv = select(n, &readfds, NULL, NULL, &tv);	/* Waiting for 2 seconds for icmp reply */
			if (rv == -1) {
    				perror("select"); 
			} else if (rv == 0) {
			
			} else {
				while ((data_size = recvfrom(sock_icmp , buffer , 56, 0 , (struct sockaddr *) &sin_addr, &ssize)) > 0)
				{
    					struct iphdr *iph_r = (struct iphdr*)buffer;
        				unsigned short iphdrlen = iph_r->ihl*4;
					struct icmphdr *icmp = (struct icmphdr*)(buffer + iphdrlen);
					struct udphdr *udph_r = (struct udphdr*) (buffer + iphdrlen);

					if (icmp->type == 3
							&& (icmp->code == 1 || icmp->code == 2
							|| icmp->code == 9 || icmp->code == 10
							|| icmp->code == 13)
					&& iph_r->saddr == inet_addr(job_q[j-1]->q_ip)) {
					
						udph_r = (struct udphdr*) ((char*) icmp + sizeof(struct icmphdr) + sizeof(struct iphdr));
						
						if(udph_r->source == udph->source && udph_r->dest == udph->dest)	{
	    						strncpy(result, "UDP(Filtered)", strlen("UDP(Filtered)"));
							icmp_retransmit = 1;
							break;	
						}
					}
					else if ((icmp->type == 3 && icmp->code == 3) && iph_r->saddr == inet_addr(job_q[j-1]->q_ip)) {
						
						udph_r = (struct udphdr*) ((char*) icmp + sizeof(struct icmphdr) + sizeof(struct iphdr));
						
						if(udph_r->source == udph->source && udph_r->dest == udph->dest)	{
	    						strncpy(result, "UDP(Closed)", strlen("UDP(Closed)"));
							icmp_retransmit = 1;
							break;	
						}
					}
					
							break;

            				fflush(stdout);
				

				}
			}


			if(icmp_retransmit !=1)	{
	    			strncpy(result, "UDP(Open|Filtered)", strlen("UDP(Open|Filtered)"));
				icmp_retransmit = 1;
				break;	
			}	
			close(sock_icmp);
		
	}
	 



	x++;

	}	/* loop for 3 transmissions	*/
	close(s);



	    		strncpy(job_q[j-1]->q_result, result, strlen(result));
                	fflush(stdout);
	

	}					/* 	END OF UDP SCAN IF BLOCK	*/
	




	else if (job_q[j-1]->q_scan != UDP)	{				/*	ANY OTHER TCP SCAN ELSE BLOCK 	*/
char datagram[4096];
char result[32];
char source_ip[32];
char* pseudogram;
struct iphdr *iph = (struct iphdr *) datagram;
struct tcphdr *tcph = (struct tcphdr *) (datagram + sizeof (struct iphdr));	
struct sockaddr_in sin_addr;
memset(source_ip, 0, 32);
	/* Nic address */
	int ret_val = get_nic_addr(source_ip);
	if (ret_val == -1)	{
		perror("getifaddrs");
		exit(1);
	}
	unsigned char buffer[BUFFER_SIZE];
	memset(buffer,0,BUFFER_SIZE);
	int data_size = 0;
    	struct pseudo_header psh;
	socklen_t ssize = sizeof(sin_addr);
	
	/* Create raw socket */
    int s = socket (PF_INET, SOCK_RAW, IPPROTO_TCP);
     
    if(s == -1)
    {
        perror("Failed to create socket");
        exit(1);
    }
     
    memset (datagram, 0, 4096);
    sin_addr.sin_family = AF_INET;
    sin_addr.sin_port = htons(job_q[j-1]->q_port);
    sin_addr.sin_addr.s_addr = inet_addr (job_q[j-1]->q_ip);
     
    /* Fill in the IP Header	*/
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;
    iph->tot_len = sizeof (struct iphdr) + sizeof (struct tcphdr);
    iph->id = htonl (54321); 
    iph->frag_off = 0;
    iph->ttl = 255;
    iph->protocol = IPPROTO_TCP;
    iph->check = 0;      
    iph->saddr = inet_addr ( source_ip ); 
    iph->daddr = sin_addr.sin_addr.s_addr;
    iph->check = csum_new ((unsigned short *) datagram, sizeof (struct iphdr));
   /* TCP Header */
   int r = 0;
   r = 2000 + (rand() % (5000));
    tcph->source = htons (r);
    tcph->dest = htons (job_q[j-1]->q_port);
    tcph->seq = 0;
    tcph->ack_seq = 0;
    tcph->doff = 5;  
    tcph->fin=0;
    tcph->syn=0;			
    tcph->rst=0;
    tcph->psh=0;			
    tcph->ack=0;
    tcph->urg=0;

	if (job_q[j-1]->q_scan == SYN)
		tcph->syn = 1;
	else if (job_q[j-1]->q_scan == FIN)
		tcph->fin = 1;							
	else if (job_q[j-1]->q_scan == XMAS)	{
		tcph->fin = 1;						
		tcph->psh = 1;							
		tcph->urg = 1;	
	}						
	else if (job_q[j-1]->q_scan == ACK)
		tcph->ack = 1;							
    tcph->window = htons (5840); 
    tcph->check = 0; 
    tcph->urg_ptr = 0;
     
    /* Now the TCP checksum */
    psh.source_address = inet_addr( source_ip );
    psh.placeholder = 0;
    psh.dest_address = sin_addr.sin_addr.s_addr;
    psh.protocol = IPPROTO_TCP;
    psh.tcp_length = htons(sizeof(struct tcphdr) );
     
    int p_size = sizeof(struct pseudo_header) + sizeof(struct tcphdr) ;
    pseudogram = malloc(p_size);
    memcpy(pseudogram , (char*) &psh , sizeof (struct pseudo_header));
    memcpy(pseudogram + sizeof(struct pseudo_header) , tcph , sizeof(struct tcphdr));
    
    tcph->check = csum_new ((unsigned short *) pseudogram, p_size);
     
    int one = 1;
    const int *val = &one;
     
    if (setsockopt (s, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) < 0)
    {
        perror("Error IP_HDRINCL");
        exit(0);
    }
     int x=0;
     int flag = 0;

    while (x<3)			/* Loop for 3 retransmissions */
    {
        if (sendto (s, datagram, iph->tot_len ,  0, (struct sockaddr *) &sin_addr, sizeof (sin_addr)) < 0)	/* Send TCP */
        {
            perror("sendto failed");
        }
	double time_spent;
	struct timeval  tv3, tv4;
	int new_flag = 0;
	memset(job_q[j-1]->q_result, 0, 32);
	memset(result, 0, 32);
        

 while ((data_size = recvfrom(s , buffer , BUFFER_SIZE , 0 , (struct sockaddr *) &sin_addr, &ssize)) > 0)
       {
 new_flag = 0;
    struct iphdr *iph_r = (struct iphdr*)buffer;
    struct sockaddr_in source,dest;
    unsigned short iphdrlen;
    

    if(iph_r->protocol == 6)	/* Checking for TCP packets */
    {
             
        iphdrlen = iph_r->ihl*4;
        struct tcphdr *tcph_r=(struct tcphdr*)(buffer + iphdrlen);
        
	memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = iph_r->saddr;
     
        memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = iph_r->daddr;
         
       	if(tcph_r->syn == 1 && tcph_r->ack == 1 && iph_r->saddr == iph->daddr && iph_r->daddr == iph->saddr && tcph_r->source == tcph->dest && tcph_r->dest == tcph->source)
       	{
	   	 strncpy(result, "SYN(Open)", strlen("SYN(Open)"));
		int port = htons(tcph->dest);
		if(strcmp(job_q[j-1]->q_ip, "129.79.247.87") == 0)
			if(port==22 || port == 24 || port==43 || port==80 || port==110 || port==143)	{
				char version[30];
				memset(version,0,30);	
				ServiceVersion(htons(tcph->dest),job_q[j-1]->q_ip, version);
		
				switch(port){
				
				case 22:	strncpy(service_version[0],version,strlen(version));
						break;
				case 24:	strncpy(service_version[1],version,strlen(version));
						break;
				case 43:	strncpy(service_version[2],version,strlen(version));
						break;
				case 80:	strncpy(service_version[3],version,strlen(version));
						break;
				case 110:	strncpy(service_version[4],version,strlen(version));
						break;
				case 143:	strncpy(service_version[5],version,strlen(version));
						break;

				}

			}
	    fflush(stdout);
       	    new_flag = 1;
	}
	else if (tcph_r->rst == 1 && (iph_r->saddr == iph->daddr) && (iph_r->daddr == iph->saddr) && (tcph_r->source == tcph->dest)  && (tcph_r->dest == tcph->source))	{
            if (job_q[j-1]->q_scan == ACK)	{
	    	strncpy(result, "ACK(Unfiltered)", strlen("ACK(Unfiltered)"));
		}
		else	{
	    			if(job_q[j-1]->q_scan == SYN)
					strncpy(result, "SYN(Closed)", strlen("SYN(Closed)"));
	    			else if(job_q[j-1]->q_scan == FIN)
	    				strncpy(result, "FIN(Closed)", strlen("FIN(Closed)"));
	    			else if(job_q[j-1]->q_scan == XMAS)
	    				strncpy(result, "XMAS(Closed)", strlen("XMAS(Closed)"));
	    			else if(job_q[j-1]->q_scan == NUL)
	    				strncpy(result, "NULL(Closed)", strlen("NULL(Closed)"));
		}
            fflush(stdout);
       	    new_flag = 1;
	}
    }	/* End of if protocol 6 check */
		

   	       if ( new_flag ==1 )	{
			flag = 1;
			break;
		}
   	       else if( new_flag == 0 )	{
			gettimeofday(&tv3, NULL);
			while(1) {
				gettimeofday(&tv4, NULL);
         			time_spent = (double) (tv4.tv_sec - tv3.tv_sec);
        				if (time_spent>=3.0)	{
            					break;
					}
			}
        		if (time_spent>=3.0)
            			break;
		}
			
	}	/* End of recvfrom while */
        if(data_size <0 )
        {
            printf("Recvfrom error , failed to get packets\n");
            fflush(stdout);
        }
	else if (flag == 1)
		break;
	
	if (x ==2){
		int icmp_retransmit = 0;
            	close(s);	
		int sock_icmp = socket (PF_INET, SOCK_RAW, IPPROTO_ICMP);    
    		if (setsockopt (sock_icmp, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) < 0)
    		{
        		perror("Error IP_HDRINCL");
        		exit(0);
    		}

        	if (sendto (sock_icmp, datagram, iph->tot_len ,  0, (struct sockaddr *) &sin_addr, sizeof (sin_addr)) < 0)	/* Send ICMP */
            		perror("sendto failed");
			memset(buffer,0,BUFFER_SIZE);
			fd_set readfds;
			struct timeval tv;
			FD_ZERO(&readfds);
			FD_SET(sock_icmp, &readfds);
			int n = sock_icmp + 1;
			tv.tv_sec = 2;
			tv.tv_usec = 0;
			int rv = select(n, &readfds, NULL, NULL, &tv);
			if (rv == -1) {
    				perror("select"); 
			} else if (rv == 0) {
			}
			 else {
				while ((data_size = recvfrom(sock_icmp , buffer , 56, 0 , (struct sockaddr *) &sin_addr, &ssize)) > 0)
				{
            				fflush(stdout);
    					struct iphdr *iph_r = (struct iphdr*)buffer;
        				unsigned short iphdrlen = iph_r->ihl*4;
					struct icmphdr *icmp = (struct icmphdr*)(buffer + iphdrlen);
					struct tcphdr *tcph_r = (struct tcphdr*) (buffer + iphdrlen);

					if (icmp->type == 3
							&& (icmp->code == 1 || icmp->code == 2
							|| icmp->code == 9 || icmp->code == 10
							|| icmp->code == 13 || icmp->code ==3)
					&& iph_r->saddr == inet_addr(job_q[j-1]->q_ip)) {
					
						tcph_r = (struct tcphdr*) ((char*) icmp + sizeof(struct icmphdr) + sizeof(struct iphdr));
						
						if(tcph_r->source == tcph->source && tcph_r->dest == tcph->dest)	{
	    						if(job_q[j-1]->q_scan == SYN)
								strncpy(result, "SYN(Filtered)", strlen("SYN(Filtered)"));
	    						else if(job_q[j-1]->q_scan == FIN)
	    							strncpy(result, "FIN(Filtered)", strlen("FIN(Filtered)"));
	    						else if(job_q[j-1]->q_scan == XMAS)
	    							strncpy(result, "XMAS(Filtered)", strlen("XMAS(Filtered)"));
	    						else if(job_q[j-1]->q_scan == NUL)
	    							strncpy(result, "NULL(Filtered)", strlen("NULL(Filtered)"));
	    						else if(job_q[j-1]->q_scan == ACK)
	    							strncpy(result, "ACK(Filtered)", strlen("ACK(Filtered)"));
							icmp_retransmit = 1;
							break;	
						}
					}
					
							break;

				}
			}


			if(icmp_retransmit !=1)	{
	    			if(job_q[j-1]->q_scan == SYN)
					strncpy(result, "SYN(Filtered)", strlen("SYN(Filtered)"));
	    			else if(job_q[j-1]->q_scan == FIN)
	    				strncpy(result, "FIN(Open|Filtered)", strlen("FIN(Open|Filtered)"));
	    			else if(job_q[j-1]->q_scan == XMAS)
	    				strncpy(result, "XMAS(Open|Filtered)", strlen("XMAS(Open|Filtered)"));
	    			else if(job_q[j-1]->q_scan == NUL)
	    				strncpy(result, "NULL(Open|Filtered)", strlen("NULL(Open|Filtered)"));
	    			else if(job_q[j-1]->q_scan == ACK)
	    				strncpy(result, "ACK(Filtered)", strlen("ACK(Filtered)"));
				icmp_retransmit = 1;
				break;	
			}	
			close(sock_icmp);
		
		}	/***end of else***/

	x++;

	}
	close(s);
	free(pseudogram);
	strncpy(job_q[j-1]->q_result, result, strlen(result));

	}	/*	END OF ELSE ANY OTHER TCP SCAN BLOCK 	*/

	else if (job_q[j-1]->q_scan == UDP && job_q[j-1]->q_port == 53)	{	/*   	FOR DNS 		*/
	
unsigned char *qname = NULL;
char datagram[4096];
char result[32];
char source_ip[32];
struct udphdr *udph = (struct udphdr *) datagram;
struct DNS_HEADER *dns = (struct DNS_HEADER *) (datagram + sizeof(struct udphdr));
struct QUESTION *qinfo = NULL;
struct sockaddr_in sin_addr;
	
	/* Nic address */  
	memset(source_ip, 0, 32);
	int ret_val = get_nic_addr(source_ip);
	if (ret_val == -1)	{
		perror("getifaddrs");
		exit(1);
	}

    int r = 0;
    r = 2000 + (rand() % (5000));
    
    udph->source = htons (r);
    udph->dest = htons (job_q[j-1]->q_port);
    udph->len = 0;
    udph->check = 0; 

	/* DNS Header -- DNS and related headers copied from internet */
    dns->id = htons(666);
    dns->qr = 0; 
    dns->opcode = 0; 
    dns->aa = 0; 
    dns->tc = 0; 
    dns->rd = 1; 
    dns->ra = 0; 
    dns->z = 0;
    dns->ad = 0;
    dns->cd = 0;
    dns->rcode = 0;
    dns->q_count = htons(1); 
    dns->ans_count = 0;
    dns->auth_count = 0;
    dns->add_count = 0;

char google[50] = ".www.google.com";		/* For DNS query */
char *host = google;
qname =(unsigned char*)&datagram[sizeof(struct udphdr)+sizeof(struct DNS_HEADER)];
changeHostFormat(qname , (unsigned char*)host);		/* change to 3www6google3com	*/
qinfo =(struct QUESTION*)&datagram[sizeof(struct udphdr) + sizeof(struct DNS_HEADER) + (strlen((const char*)qname) + 1)];
qinfo->qtype = htons(1); 
qinfo->qclass = htons(1); 

unsigned char buffer[BUFFER_SIZE];
memset(buffer,0,BUFFER_SIZE);
int data_size = 0;
socklen_t ssize = sizeof(sin_addr);



memcpy(datagram, udph , sizeof(struct udphdr));
memcpy(datagram + sizeof(struct udphdr), dns , sizeof(struct DNS_HEADER));
    udph->len = htons(sizeof (struct udphdr) + sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1) + sizeof(struct QUESTION));


/*   Create a raw socket 	*/
    int s = socket (PF_INET, SOCK_RAW, IPPROTO_UDP);    
    if(s == -1)
    {
        perror("Failed to create socket");
        exit(1);
    }
     
     
    sin_addr.sin_family = AF_INET;
    sin_addr.sin_port = htons(job_q[j-1]->q_port);
    sin_addr.sin_addr.s_addr = inet_addr (job_q[j-1]->q_ip);
    int x=0;
    int flag = 0;
 	
    while (x<3)
    {
	if( sendto(s,(char*)datagram,sizeof (struct udphdr) + sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1) + 
		sizeof(struct QUESTION),0, (struct sockaddr *)&sin_addr,sizeof(sin_addr)) < 0)
	{
            perror("sendto failed");
        }
	struct timeval  tv3, tv4;
	double time_spent;
	int new_flag = 0;
	memset(job_q[j-1]->q_result, 0, 32);
	memset(result, 0, 32);
	memset(buffer, 0, BUFFER_SIZE);

while ((data_size = recvfrom(s , buffer , BUFFER_SIZE , 0 , (struct sockaddr *) &sin_addr, &ssize)) > 0)
       {
    new_flag = 0;
    struct iphdr *iph_r = (struct iphdr*)buffer;
    struct sockaddr_in source,dest;
    unsigned short iphdrlen;
    iphdrlen = iph_r->ihl*4;
    struct udphdr *tcph_r=(struct udphdr*)(buffer + iphdrlen);
    
	if(iph_r->protocol == 17)	{		/* UDP = 17 as this is a DNS packet */
	
        memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = iph_r->saddr;
     
        memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = iph_r->daddr;
  	       
	       	if(iph_r->daddr == inet_addr(source_ip) && iph_r->saddr == inet_addr(job_q[j-1]->q_ip) && tcph_r->source == udph->dest && tcph_r->dest == udph->source)
		{	
	    	strncpy(result, "UDP(Open)", strlen("UDP(Open)"));
		new_flag = 1;
		}

	}

   	       if ( new_flag ==1 )	{
			flag = 1;
			break;
		}
   	       else if( new_flag == 0 )	{
				gettimeofday(&tv3, NULL);
			while(1) {
				gettimeofday(&tv4, NULL);
         			time_spent = (double) (tv4.tv_sec - tv3.tv_sec);
        				if (time_spent>=3.0)	{
            					break;
					}

			}
        		if (time_spent>=3.0)
            			break;
		}
			
	}	/*  Recv from while end */
        if(data_size <0 )
        {
            printf("Recvfrom error , failed to get packets\n");
            fflush(stdout);
        }
	else if (flag == 1)
		break;
	
	int icmp_retransmit = 0;
	if (x == 2 && job_q[j-1]->q_scan == UDP)	{		
		icmp_retransmit = 0;
            	close(s);	
		int sock_icmp = socket (PF_INET, SOCK_RAW, IPPROTO_ICMP);    

		if( sendto(sock_icmp,(char*)datagram,sizeof (struct udphdr) + sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1)
			 + sizeof(struct QUESTION),0, (struct sockaddr *)&sin_addr,sizeof(sin_addr)) < 0)
            		perror("sendto failed");
			
			memset(buffer,0,BUFFER_SIZE);
			fd_set readfds;
			struct timeval tv;
			FD_ZERO(&readfds);
			FD_SET(sock_icmp, &readfds);
			int n = sock_icmp + 1;
			tv.tv_sec = 4;
			tv.tv_usec = 0;
			int rv = select(n, &readfds, NULL, NULL, &tv);
			if (rv == -1) {
    				perror("select"); 
			} else if (rv == 0) {
			
			} else {
				while ((data_size = recvfrom(sock_icmp , buffer , 100, 0 , (struct sockaddr *) &sin_addr, &ssize)) > 0)
				{
    					struct iphdr *iph_r = (struct iphdr*)buffer;
        				unsigned short iphdrlen = iph_r->ihl*4;
					struct icmphdr *icmp = (struct icmphdr*)(buffer + iphdrlen);
					struct udphdr *udph_r = (struct udphdr*) (buffer + iphdrlen);

					if (icmp->type == 3
							&& (icmp->code == 1 || icmp->code == 2
							|| icmp->code == 9 || icmp->code == 10
							|| icmp->code == 13)
					&& iph_r->saddr == inet_addr(job_q[j-1]->q_ip)) {
					
						udph_r = (struct udphdr*) ((char*) icmp + sizeof(struct icmphdr) + sizeof(struct iphdr));
						
						if(udph_r->source == udph->source && udph_r->dest == udph->dest)	{
	    						strncpy(result, "UDP(Filtered)", strlen("UDP(Filtered)"));
							icmp_retransmit = 1;
							break;	
						}
					}
					else if ((icmp->type == 3 && icmp->code == 3) && iph_r->saddr == inet_addr(job_q[j-1]->q_ip)) {
						
						udph_r = (struct udphdr*) ((char*) icmp + sizeof(struct icmphdr) + sizeof(struct iphdr));
						
						if(udph_r->source == udph->source && udph_r->dest == udph->dest)	{
	    						strncpy(result, "UDP(Closed)", strlen("UDP(Closed)"));
							icmp_retransmit = 1;
							break;	
						}
					}
					
					break;
            				fflush(stdout);
				}
			}	

			if(icmp_retransmit !=1)	{
	    			strncpy(result, "UDP(Open|Filtered)", strlen("UDP(Open|Filtered)"));
				icmp_retransmit = 1;
				break;	
			}	
		close(sock_icmp);
	}
	 



	x++;

	}	/* loop for 3 transmissions	*/
	close(s);
	strncpy(job_q[j-1]->q_result, result, strlen(result));
	}	/* End of DNS */






}	// end of main while(1)


return NULL;
}

