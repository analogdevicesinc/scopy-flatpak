TARGET := Scopy.flatpak
SRC := org.adi.Scopy.json

ifndef ARCH
	ARCH := x86_64
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): repo
	flatpak build-bundle $< $@ org.adi.Scopy

repo: build
	flatpak build-export $@ $<

build: preprocess
	flatpak-builder --verbose --arch=$(ARCH) $@ $(SRC)

preprocess: clean
	if [ $(ARCH) = x86_64 ]; then \
  		echo "-- Preprocessing org.adi.Scopy.json for ARCH = X86_64"; \
  		gcc -E -P -D__X86__ org.adi.Scopy.json.c -o org.adi.Scopy.json; \
  	elif [ $(ARCH) = arm ]; then \
  	  	echo "-- Preprocessing org.adi.Scopy.json for ARCH = arm"; \
  	  	gcc -E -P -D__ARM__ org.adi.Scopy.json.c -o org.adi.Scopy.json; \
  	fi

clean:
	rm -rf $(TARGET) build repo
