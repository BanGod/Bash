#define _GNU_SOURCE // Для использования констант максимальных значений 
#include <limits.h> // длины пути, хоста и имени пользователя
#include <unistd.h> // Для использования команд bash
#include <stdio.h> 
#include <stdlib.h> // Для определения домашней директории
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../0_general/general.h"

void AppendWrite(Arrs double_arrow) {
    int open_res = 0;
    for (int v = 0; v < double_arrow.length - 1; v++) {
        open_res = open(double_arrow.file_name[v], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
        if (open_res != -1) {
            close(open_res);
        }
    }
}

void TruncWrite(Arrs arrow) {
    int open_res = 0;
    for (int v = 0; v < arrow.length - 1; v++) {
        open_res = open(arrow.file_name[v], O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
        if (open_res != -1) {
            close(open_res);
        }
    }
}

int Read(Arrs back_arrow) {
    int open_res = 0;
    for (int v = 0; v < back_arrow.length - 1; v++) {
        open_res = open(back_arrow.file_name[v], O_RDONLY, S_IRWXU);
        printf("%d", open_res);
        if (open_res != -1) {
            close(open_res);
        }
        else {
            printf("bash: %s: Нет такого файла или каталога", back_arrow.file_name[v]);
            return 0;
        }
    }
    return 1;
}

