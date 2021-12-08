#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <chrono>
#include <ctime>
#include <unistd.h>

using namespace std;

void help();
void drama();
void anecdote();


int main(int argc, char *argv[]) {
    int rez = -1;
    int option_index;
    const char* short_options = "hda";
    const struct option long_options[] = {
            {"help",no_argument,NULL,'h'},
            {"drama",no_argument,NULL,'d'},
            {"anecdote",no_argument,NULL,'a'},
            {NULL,0,NULL,0}
    };
    int h_counter = 1;
    int d_counter = 1;
    int a_count = 1;


    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index))  != -1) {
        switch(rez){
            case 'h': {
                if (h_counter < 1){
                    goto exitH;
                }
                h_counter--;
                help();
                exitH: break;
            }
            case 'd': {
                if (d_counter < 1){
                    goto exitV;
                }
                d_counter--;
                drama();

                exitV: break;
            }

            case 'a': {
                if (a_count < 1){
                    goto exitA;
                }
                a_count--;
                anecdote();

                exitA: break;
            }

            case '?': default: {
                printf("Option not supported\n");
                break;
            }
        }
    }
}

void help()
{
    printf("-h (--help) выводит эту подсказку\n"
           "-a (--anec) рассказывает несмешной анекдот\n"
           "-d (--drama) рассказывает тот же анекдот, что и выше, но с драматическими паузами\n");
}

void drama()
{
    printf("Идет медведь по лесу...\n\n");
    usleep (3000000);
    printf("...Видит - машина горит...\n\n");
    usleep (3000000);
    printf("...Сел в нее...\n\n");
    usleep (3000000);
    printf("...и сгорел...\n");
    usleep (2000000);
}

void anecdote(){
    printf("Идет медведь по лесу, видит - машина горит. Сел в нее и сгорел.\n");
}
