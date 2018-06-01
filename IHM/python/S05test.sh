#! /bin/sh
### BEGIN INIT INFO
# Provides:          checkroot mtab
# Required-Start:    mountdevsubfs hostname
# Required-Stop:     
# Should-Start:      keymap hwclockfirst hdparm bootlogd
# Should-stop:
# Default-Start:     S
# Default-Stop:
# X-Interactive:     true
# Short-Description: Check to root file system.
### END INIT INFO

case "$1" in
  start|"")
	export DISPLAY=:0.0
        /home/pi/IHM_robot.py
	;;
  restart|reload|force-reload)
	echo "Error: argument '$1' not supported" >&2
	exit 3
	;;
  stop)
	# No-op
	;;
  status)
	do_status
	exit $?
	;;
  *)
	echo "Usage: checkroot.sh [start|stop]" >&2
	exit 3
	;;
esac

:
