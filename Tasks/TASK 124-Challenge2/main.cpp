#include "mbed.h"

BusOut leds(PC_7,PC_8,PC_9);

int main() {
    int pattern, count, delay;
    
    while (true) {
        do {
            printf("Enter a pattern (0-7): ");
            scanf("%d", &pattern);
        } while (pattern < 0 || pattern > 7);
        
        do {
            printf("Enter a count (5-20): ");
            scanf("%d", &count);
        } while (count < 5 || count > 20);
        
        do {
            printf("Enter a delay (50-2000 ms): ");
            scanf("%d", &delay);
        } while (delay < 50 || delay > 2000);
        
        for (int i = 0; i < count; i++) {
            
        }
    }
}



