#!/bin/sh

killall dwm
dwm &> /dev/null &
disown
