#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        syslog(LOG_ERR, "Incorrect number of arguments.");
        return 1;
    }

    const char *file_path = argv[1];
    const char *text_to_write = argv[2];

    // Open file for writing
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file: %s", file_path);
        return 1;
    }

    // Write text to file
    fprintf(file, "%s", text_to_write);
    fclose(file);

    // Log the success
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", text_to_write, file_path);

    return 0;
}
