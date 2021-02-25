TARGET := Scopy.flatpak
SRC := org.adi.Scopy.json
ARCH := x86_64

.PHONY: all clean

all: $(TARGET)

$(TARGET): repo
	flatpak build-bundle $< $@ org.adi.Scopy

repo: build
	flatpak build-export $@ $<

build: clean
	flatpak-builder --verbose --arch=$(ARCH) $@ $(SRC)

clean:
	rm -rf $(TARGET) build repo
