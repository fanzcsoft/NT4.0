/**********************************************************************/
/**                       Microsoft Windows NT                       **/
/**                Copyright(c) Microsoft Corp., 1993                **/
/**********************************************************************/

/*
    inetctrs.h

    Offset definitions for the INET Server's counter objects & counters.

    These offsets *must* start at 0 and be multiples of 2.  In the
    INETOpenPerformanceData procecedure, they will be added to the
    INET Server's "First Counter" and "First Help" values in order to
    determine the absolute location of the counter & object names
    and corresponding help text in the registry.

    This file is used by the INETCTRS.DLL DLL code as well as the
    INETCTRS.INI definition file.  INETCTRS.INI is parsed by the
    LODCTR utility to load the object & counter names into the
    registry.


    FILE HISTORY:
        KeithMo     07-Jun-1993 Created.
        MuraliK     02-Jun-1995 Added Counters for Atq I/O requests

*/


#ifndef _INETCTRS_H_
#define _INETCTRS_H_


//
//  The INET Server counter object.
//

#define INET_COUNTER_OBJECT                     0


//
//  The individual counters.
//

#define INET_CACHE_BYTES_TOTAL_COUNTER                  2
#define INET_CACHE_BYTES_IN_USE_COUNTER                 4
#define INET_CACHE_OPEN_FILES_COUNTER                   6
#define INET_CACHE_DIR_LISTS_COUNTER                    8
#define INET_CACHE_OBJECTS_COUNTER                      10
#define INET_CACHE_FLUSHES_COUNTER                      12
#define INET_CACHE_HITS_COUNTER                         14
#define INET_CACHE_MISSES_COUNTER                       16
#define INET_CACHE_RATIO_COUNTER                        18
#define INET_CACHE_RATIO_COUNTER_DENOM                  20
#define INET_ATQ_TOTAL_ALLOWED_REQUESTS_COUNTER         22
#define INET_ATQ_TOTAL_BLOCKED_REQUESTS_COUNTER         24
#define INET_ATQ_TOTAL_REJECTED_REQUESTS_COUNTER        26
#define INET_ATQ_CURRENT_BLOCKED_REQUESTS_COUNTER       28
#define INET_ATQ_MEASURED_BANDWIDTH_COUNTER             30



#endif  // _INETCTRS_H_

