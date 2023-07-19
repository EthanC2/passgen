#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main(int argc, char **argv)
{
    const char *charset = 
                        "abcdefghijklmnopqrstuvwxyz"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "0123456789"
                        " !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
    char *password = NULL;
    size_t setlen = strlen(charset), passlen;
    srandom(time(NULL));

    if (argc < 2)
    {
        fputs("usage: passgen <LENGTH:int>", stderr);
    }

    passlen = strtoull(argv[1], NULL, 10);
    if (errno == ERANGE || passlen == 0)
    {
        if (errno == ERANGE)
        {
            errno = 0;
        }

        fputs("<LENGTH:int> must be in the range 1..INT64_MAX", stderr);
    }

    
    password = (char*) malloc((passlen+1) * sizeof(char));
    
    for(size_t i=0; i < passlen; ++i)
    {
        password[i] = charset[random() % setlen];
    }

    password[passlen] = '\0';
    printf("password: %s\n", password);
    
    free(password);

    return EXIT_SUCCESS;
}