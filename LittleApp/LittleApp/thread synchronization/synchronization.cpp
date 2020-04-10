#include "synchronization.h"


mutex Sync::lock1;
bool Sync::b1=true;


shared_mutex Sync::lock2;
bool Sync::b2 = true;