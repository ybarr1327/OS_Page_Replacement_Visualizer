This program is meant to simulate the different paging replacement algorithms that an operating system can use.

The algorithms exemplified by this program include the following:
First in First out
Random
LRU (Least Recently Used) algorithm


To run this program you must provide the follwing arguments when running on the command line:
 - page size (in bytes): between 256 and 8192, inclusive
 - physical memory size (in megabytes): between 4 and 64, inclusive

See 'Programming Assignment 5 Report' for an in depth analysis of the algorithms

Example Run:
 ./prog5 256 4
=================================================================
CS 433 Programming assignment 5
Author: Gabriel Ybarra and Ryan Lochrane
Date: 12/1/2020
Course: CS433 (Operating Systems)
Description : Program to simulate different page replacement algorithms
=================================================================

Page size = 256 bytes
Physical Memory size = 4194304 bytes
Number of pages = 524288
Number of physical frames = 16384

================================Test 1==================================================
Logical Address: 101853141,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 1
Logical Address: 101853027,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 72042423,      Page Number: 281415,    Frame Number = 1,       Is Page Fault? 1
Logical Address: 71971407,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 1
Logical Address: 72084158,      Page Number: 281578,    Frame Number = 3,       Is Page Fault? 1
Logical Address: 101853169,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101854129,     Page Number: 397867,    Frame Number = 4,       Is Page Fault? 1
Logical Address: 71978895,      Page Number: 281167,    Frame Number = 5,       Is Page Fault? 1
Logical Address: 101853144,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853141,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853170,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853121,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853141,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 72272062,      Page Number: 282312,    Frame Number = 6,       Is Page Fault? 1
Logical Address: 71755731,      Page Number: 280295,    Frame Number = 7,       Is Page Fault? 1
Logical Address: 71971493,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 71990563,      Page Number: 281213,    Frame Number = 8,       Is Page Fault? 1
Logical Address: 101853042,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71971458,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853338,     Page Number: 397864,    Frame Number = 9,       Is Page Fault? 1
Logical Address: 101853142,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853149,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71917530,      Page Number: 280927,    Frame Number = 10,      Is Page Fault? 1
Logical Address: 101853141,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71971394,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853140,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853140,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71854261,      Page Number: 280680,    Frame Number = 11,      Is Page Fault? 1
Logical Address: 71979860,      Page Number: 281171,    Frame Number = 12,      Is Page Fault? 1
Logical Address: 71721778,      Page Number: 280163,    Frame Number = 13,      Is Page Fault? 1
Logical Address: 71971404,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 71971472,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853133,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853141,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853744,     Page Number: 397866,    Frame Number = 14,      Is Page Fault? 1
Logical Address: 71971545,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853140,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853140,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853744,     Page Number: 397866,    Frame Number = 14,      Is Page Fault? 0
Logical Address: 101853147,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71697486,      Page Number: 280068,    Frame Number = 15,      Is Page Fault? 1
Logical Address: 71971350,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 71987865,      Page Number: 281202,    Frame Number = 16,      Is Page Fault? 1
Logical Address: 72439020,      Page Number: 282964,    Frame Number = 17,      Is Page Fault? 1
Logical Address: 71971404,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853136,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71971551,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 71971418,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 71971521,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 71566676,      Page Number: 279557,    Frame Number = 18,      Is Page Fault? 1
Logical Address: 71970526,      Page Number: 281134,    Frame Number = 19,      Is Page Fault? 1
Logical Address: 101853028,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853034,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853143,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71957576,      Page Number: 281084,    Frame Number = 20,      Is Page Fault? 1
Logical Address: 71972234,      Page Number: 281141,    Frame Number = 21,      Is Page Fault? 1
Logical Address: 101853148,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71965339,      Page Number: 281114,    Frame Number = 22,      Is Page Fault? 1
Logical Address: 101853141,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101852398,     Page Number: 397860,    Frame Number = 23,      Is Page Fault? 1
Logical Address: 71982260,      Page Number: 281180,    Frame Number = 24,      Is Page Fault? 1
Logical Address: 101853123,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71768626,      Page Number: 280346,    Frame Number = 25,      Is Page Fault? 1
Logical Address: 101853483,     Page Number: 397865,    Frame Number = 26,      Is Page Fault? 1
Logical Address: 101853139,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71971410,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853141,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853550,     Page Number: 397865,    Frame Number = 26,      Is Page Fault? 0
Logical Address: 101853801,     Page Number: 397866,    Frame Number = 14,      Is Page Fault? 0
Logical Address: 101853576,     Page Number: 397865,    Frame Number = 26,      Is Page Fault? 0
Logical Address: 71946808,      Page Number: 281042,    Frame Number = 27,      Is Page Fault? 1
Logical Address: 101853140,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71922510,      Page Number: 280947,    Frame Number = 28,      Is Page Fault? 1
Logical Address: 71971404,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853144,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 72005148,      Page Number: 281270,    Frame Number = 29,      Is Page Fault? 1
Logical Address: 71971418,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101852526,     Page Number: 397861,    Frame Number = 30,      Is Page Fault? 1
Logical Address: 71971522,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853140,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71990332,      Page Number: 281212,    Frame Number = 31,      Is Page Fault? 1
Logical Address: 101853002,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71971405,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 71971418,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853140,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853640,     Page Number: 397865,    Frame Number = 26,      Is Page Fault? 0
Logical Address: 101853140,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 72170392,      Page Number: 281915,    Frame Number = 32,      Is Page Fault? 1
Logical Address: 71971561,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 72034799,      Page Number: 281385,    Frame Number = 33,      Is Page Fault? 1
Logical Address: 101853138,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853192,     Page Number: 397864,    Frame Number = 9,       Is Page Fault? 0
Logical Address: 71971404,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 101853141,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 101853147,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71839460,      Page Number: 280622,    Frame Number = 34,      Is Page Fault? 1
Logical Address: 101853782,     Page Number: 397866,    Frame Number = 14,      Is Page Fault? 0
Logical Address: 101853138,     Page Number: 397863,    Frame Number = 0,       Is Page Fault? 0
Logical Address: 71971390,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Logical Address: 71971405,      Page Number: 281138,    Frame Number = 2,       Is Page Fault? 0
Number of references:           100
Number of page faults:          35
Number of replacements:         0

================================Test 2==================================================
Total Number of references: 2000000
****************Simulate FIFO replacement****************************
Number of references:           2000000
Number of page faults:          340108
Number of replacements:         323724
Elapsed Time: 0.0796945 seconds
****************Simulate Random replacement****************************
Number of references:           2000000
Number of page faults:          354740
Number of replacements:         338356
Elapsed Time: 0.0692511 seconds
****************Simulate LRU replacement****************************
Number of references:           2000000
Number of page faults:          233509
Number of replacements:         217125
Elapsed Time: 0.138349 seconds