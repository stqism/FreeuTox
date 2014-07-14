#include<libintl.h>
#include<locale.h>

#define AFS(x) { .str = (uint8_t*)x, .length = sizeof(x) - 1 }
#define _(String) gettext (String)

static STRING addstatus[] = {
    AFS(_("Friend request sent. Your friend will appear online after accepting it.")),
    AFS(_("Attempting to resolve DNS name...")),
    AFS(_("Error: Invalid Tox ID")),
    AFS(_("Error: No Tox ID specified")),
    AFS(_("Error: Message is too long")),
    AFS(_("Error: Empty message")),
    AFS(_("Error: Tox ID is self ID")),
    AFS(_("Error: Tox ID is already in friend list")),
    AFS(_("Error: Unknown")),
    AFS(_("Error: Invalid Tox ID (bad checksum)")),
    AFS(_("Error: Invalid Tox ID (bad nospam value)")),
    AFS(_("Error: No memory"))
};

STRING filestatus[] = {
    AFS(_("New file transfer")),
    AFS(_("File transfer started")),
    AFS(".."),
    AFS(_("File transfer paused")),
    AFS(_("File transfer broken")),
    AFS(_("File transfer cancelled")),
    AFS(_("File transfer complete"))
};

STRING callstatus[] = {
    AFS(_("Call cancelled")),
    AFS(_("Call invited")),
    AFS(_("Call ringing")),
    AFS(_("Call started"))
};

#undef AFS
