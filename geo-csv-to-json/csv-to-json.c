/**
 * A tool that converts comma separated data (from a GPS device) from command line and displays it
 * in JSON format.
 */
#include <stdio.h>

int main(void)
{
    float latitude, longitude;
    char info[80];
    int started = 0;

    puts("data=[");
    /* Reads in CSV */
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
    {
        /* Print a comma if there was a previous line*/
        if (started)
        {
            printf(",\n");
        }
        else
        {
            started = 1;
        }
        if (latitude > 90.0 || latitude < -90.0)
        {
            printf("Invalid latitude: %f", latitude);
            return (-2);
        }
        else if (longitude > 180.0 || longitude < -180.0)
        {
            printf("Invalid longitude: %f", longitude);
            return (-2);
        }
        printf("{latitude: %f,longitude: %f,info: '%s'}", latitude, longitude, info);
    }
    putchar('\n');
    return (0);
}