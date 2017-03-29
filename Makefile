TARGET := Scopy.flatpak
SRC := org.adi.Scopy.json

.PHONY: all clean

all: $(TARGET)

$(TARGET): repo
	flatpak build-bundle $< $@ org.adi.Scopy

repo: build
	flatpak build-export $@ $<

build: clean
	flatpak-builder $@ $(SRC)

clean:
	rm -rf $(TARGET) build repo
