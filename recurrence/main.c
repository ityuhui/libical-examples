#include <libical/ical.h>
#include <stdio.h>

int main()
{
    struct icalrecurrencetype rrule;
    struct icaltimetype dtstart, next;
    icalrecur_iterator *ritr;
    
    //const char *dtstart_string = "19980101T090000";
    const char *rrule_string = "FREQ=YEARLY;UNTIL=20210131T140000Z;BYMONTH=1;BYDAY=SU,MO,TU,WE,TH,FR,SA";

    //dtstart = icaltime_from_string(dtstart_string);
    dtstart = icaltime_current_time_with_zone(NULL);
    printf("Now=%s\n", icaltime_as_ical_string(dtstart));
    

    rrule = icalrecurrencetype_from_string(rrule_string);
    ritr = icalrecur_iterator_new(rrule, dtstart);

    for (next = icalrecur_iterator_next(ritr);
        !icaltime_is_null_time(next);
        next = icalrecur_iterator_next(ritr)) {
        printf("%ld\n", icaltime_as_timet(next));
        printf("%ld\n", icaltime_as_timet_with_zone(next, NULL));
        printf("%s\n", icaltime_as_ical_string(next));
    }
    printf("\n");

    return 0;
}
