#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define TRUE        1
#define FALSE       0

int greedySelector(int EVENTS_NUM, int *sTime, int *eTime, bool *events) {
    events[0] = TRUE;
    int j = 0, cnt = 1;

    for (int i = 1; i < EVENTS_NUM; i++) {
        if (sTime[i] >= eTime[j]) {
            events[i] = TRUE;
            j = i;
            cnt++;
        }else events[i] = FALSE;
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    if (argc <= 2) {
        printf("Input format: ./events_manage [start time array] [end time array]\n");
        return -1;
    }
    if (strlen(argv[2]) != strlen(argv[1])) {
        printf("Input format error: the length of start time array is not equal to end time array!\n");
        return -1;
    }
    int EVENTS_NUM = strlen(argv[1]);
    int *sTime = (int *)malloc(sizeof(int) * EVENTS_NUM);
    int *eTime = (int *)malloc(sizeof(int) * EVENTS_NUM);
    bool *events = (bool *)malloc(sizeof(bool) * EVENTS_NUM);
    for (int i = 0; i < EVENTS_NUM; i++) {
        sTime[i] = *(argv[1] + i) - '0';
        eTime[i] = *(argv[2] + i) - '0';
    }

    int cnt = greedySelector(EVENTS_NUM, sTime, eTime, events);
    printf("Results: \n");
    for (int i = 0; i < EVENTS_NUM; i++) {
        printf("[%d]: ", i);
        printf("%d\n", events[i]);
    }
    printf("Totally %d events are managed.\n", cnt);
    return 0;
}
