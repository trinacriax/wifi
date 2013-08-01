wifi
====

This module improves the wifi module for the ns-3 simulator. 
It introduce a TAG to measure the SNR of the specified packet/message
that can be used at the application level to make smart decisions.
In addition, it provides a new mechanism to measure the amount of time a node 
finds the channels busy: the wifi channel availability can be computed in a distirbuted fashion during the simulation time.
