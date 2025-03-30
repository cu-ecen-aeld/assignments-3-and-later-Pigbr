#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "error: need two arguments\n");
        exit(1);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open syslog for logging
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Log the debug message
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // Open the file for writing
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "error: can't create %s", writefile);
        perror("fopen");
        exit(1);
    }

    // Write the string to the file
    fprintf(file, "%s", writestr);

    // Close the file and syslog
    fclose(file);
    closelog();

    return 0;
}
