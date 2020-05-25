#include <libical/ical.h>
#include <stdio.h>

int main()
{
    const char *str="PT1H1M3S";

    struct icaldurationtype duration = icaldurationtype_from_string(str);

    if (0 == icaldurationtype_is_bad_duration(duration)) {
        time_t dur = icaldurationtype_as_int(duration);
        printf("%s=%ld\n", str, dur);
    }

    return 0;
}
