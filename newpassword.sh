#!/bin/bash
passwordstatus="$HOME/.config/np"

if [ -f $passwordstatus ]; then
	echo "dosya var"
	
else
	echo "dosya yok"
	touch $passwordstatus
	notify-send -i password "İlk Defa Oturum Açıyorsunuz.." -u critical
	
	notify-send -i password "Şifrenizi Mutlaka Değiştirin.." -u critical
	/usr/bin/sifredegistir
	
fi
