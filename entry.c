//
//  entry.c
//  
//
//  Created by Shashank Shankar on 10/15/14.
//
//

#include <stdio.h>
#include "avltree.h"


/* Entry is this particular data entry, message is the journal entry you want to save. Assumes all data is preallocated. Message should be an argv[] input so can use strlen*/
void createEntry (Entry* entry, char* message){
    struct tm* time;
    time_t rawtime;
    
    entry->getTimeAsString = getTimeAsString;
    entry->getMessage = getMessage;
    
    entry->dataEntry = strdup(message);
    time( &rawtime );
    time = localtime( &rawtime );
    entry->timeStamp = time;
}

char* getTimeAsString(Entry* entry){
    return asc(entry->timeStamp);
}

char* getMessage(Entry* entry){
    return entry->message;
}