#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    time_t now;
    struct tm *now_tm;
    int hours, minutes, seconds, total_seconds;
    char command[50];

    // 获取当前的时间
    now = time(NULL);
    now_tm = localtime(&now);

    // 获取当前的小时、分钟和秒数
    hours = now_tm->tm_hour;
    minutes = now_tm->tm_min;
    seconds = now_tm->tm_sec;

    printf("Current time: %02d:%02d:%02d\n", hours, minutes, seconds);

    // 将小时、分钟和秒数转换为总的秒数
    total_seconds = hours * 3600 + minutes * 60 + seconds;

    printf("Total seconds: %d\n", total_seconds);

    // 设置 monthly_time 的值
    sprintf(command, "nv set monthly_time=%d", total_seconds);
    system(command);

    return 0;
}
