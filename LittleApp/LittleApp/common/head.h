#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <set>
#include <map>
#include <thread>
#include "memory"
#include <mutex>
#include <shared_mutex>
#include <errno.h> // errno 变量的头文件

#ifdef WIN32
#include <windows.h>
#else
#endif // WIN32

using namespace std;

//#define pp(out) cout <<"line:"<<__LINE__<<"---" << out << "------##" << endl;
#define po(out) cout << out ;
//#define pr(out) cout << out << endl;




