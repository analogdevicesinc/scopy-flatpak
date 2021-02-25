#!/bin/bash
cd /tmp
git clone https://github.com/computermouth/qemu-static-conf.git
sudo mkdir -p /lib/binfmt.d
sudo cp qemu-static-conf/*.conf /lib/binfmt.d/

sudo service systemd-binfmt restart
service systemd-binfmt status
#sudo systemctl restart systemd-binfmt.service
#systemctl status systemd-binfmt
