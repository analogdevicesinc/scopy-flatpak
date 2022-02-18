#include "defined_variables.h"

{
	"app-id": "org.adi.Scopy",
	"runtime": "org.kde.Platform",
	"runtime-version": EXPAND(RUNTIME_VERSION),
	"sdk": "org.kde.Sdk",
	"command": "scopy",
	"rename-desktop-file": "scopy.desktop",
	"rename-icon": "scopy",
	"finish-args": [
		"--socket=x11",
		"--socket=wayland",
                "--socket=pulseaudio",
		"--share=network",
		"--share=ipc",
		"--filesystem=host:create",
		"--filesystem=~/.config/dconf:create",
		"--filesystem=xdg-config/ADI:create",
		"--device=all"
	],

	"build-options" : {
		"cflags": "-O2 -g",
		"cxxflags": "-O2 -g",
		"env": {
			"V": "1"
		}

	},
	"cleanup": [
		"/include",
		"/lib/python2.7",
		"/lib/pkgconfig",
		"/lib/cmake",
		"/lib/*.la",
		"/lib/*.a",
		"/lib/gio",
		"/lib/giomm-2.4",
		"/lib/glibmm-2.4",
		"/lib/libzip",
		"/lib/libgthread*",
		"/lib/sigc++-2.0",
		"/lib/xml2Conf.sh"
	],
	"modules": [
		{
			"name": "sshpass",
			"sources": [
				{
					"type": "archive",
					"url": "https://sourceforge.net/projects/sshpass/files/sshpass/1.08/sshpass-1.08.tar.gz",
					"sha1": "efe4573ba2fe972b08cf1cdd95739b7f456e55c1"
				}
			]
		},
		{
			"name": "log4cpp",
			"config-opts": [ "--prefix=/app" ],
			"sources": [
				{
					"type": "archive",
					"url": "https://sourceforge.net/projects/log4cpp/files/latest/log4cpp-1.1.3.tar.gz",
					"sha1": "74f0fea7931dc1bc4e5cd34a6318cd2a51322041",
					"strip-components": 2
				}
			]
		},
		{
			"name": "libusb",
			"config-opts": [ "--disable-udev", "--prefix=/app" ],
			"sources": [
				{
					"type": "archive",
					"url": "https://downloads.sourceforge.net/project/libusb/libusb-1.0/libusb-1.0.24/libusb-1.0.24.tar.bz2",
					"sha256": "7efd2685f7b327326dcfb85cee426d9b871fd70e22caa15bb68d595ce2a2b12a"
				}
			]
		},
		{
			"name": "boost",
			"cleanup": [ "/bin", "/share" ],
			"sources": [
				{
					"type": "archive",
					"url": "https://boostorg.jfrog.io/artifactory/main/release/1.72.0/source/boost_1_72_0.tar.gz",
					"sha256": "c66e88d5786f2ca4dbebb14e06b566fb642a1a6947ad8cc9091f9f445134143f"
				},
				{
					"type": "script",
					"commands": [
						"#!/bin/sh",
						"exec ./bootstrap.sh --with-libraries=date_time,filesystem,program_options,regex,system,test,thread,atomic,chrono --prefix=/app"
					],
					"dest-filename": "configure"
				},
				{
					"type": "script",
					"commands": [
						"all:",
						"\t./b2",
						"install:",
						"\t./b2 install"
					],
					"dest-filename": "Makefile"
				}
			]
		},
		{
			"name": "glib",
			"cleanup": [ "/bin", "/share" ],
			"config-opts": [ "--prefix=/app" ],
			"sources": [
				{
					"type": "archive",
					"url": "http://ftp.gnome.org/pub/gnome/sources/glib/2.58/glib-2.58.3.tar.xz",
					"sha256": "8f43c31767e88a25da72b52a40f3301fefc49a665b56dc10ee7cc9565cbe7481"
				}
			]
		},
		{
			"name": "sigcpp",
			"config-opts": ["--prefix=/app" ],
			"cleanup": [ "/bin", "/share" ],
			"sources": [
				{
					"type": "archive",
					"url": "http://ftp.acc.umu.se/pub/GNOME/sources/libsigc++/2.10/libsigc++-2.10.0.tar.xz",
					"sha256": "f843d6346260bfcb4426259e314512b99e296e8ca241d771d21ac64f28298d81"
				}
			]
		},
		{
			"name": "glibmm",
			"cleanup": [ "/bin", "/share" ],
			"sources": [
				{
					"type": "archive",
					"url": "http://ftp.acc.umu.se/pub/gnome/sources/glibmm/2.58/glibmm-2.58.1.tar.xz",
					"sha256": "6e5fe03bdf1e220eeffd543e017fd2fb15bcec9235f0ffd50674aff9362a85f0"
				}
			]
		},
		"shared-modules/dbus-glib/dbus-glib-0.110.json",
		{
			"name": "dbus-glib-submodule"
		},
		"shared-modules/intltool/intltool-0.51.json",
		{
			"name": "intltool-submodule"
		},
#ifndef __ARM__
		{
		    "name": "dbus-python",
		    "sources": [
                {
                    "type": "archive",
                    "url": "https://dbus.freedesktop.org/releases/dbus-python/dbus-python-1.2.16.tar.gz",
                    "sha256": "11238f1d86c995d8aed2e22f04a1e3779f0d70e587caffeab4857f3c662ed5a4"
                }
			]
		},
#endif
		{
			"name": "avahi",
			"config-opts": [
				"--disable-monodoc",
				"--disable-gtk",
				"--disable-gtk3",
				"--disable-qt3",
				"--disable-qt4",
				"--disable-pygobject",
				"--disable-gdbm",
				"--disable-libdaemon",
				"--disable-mono",
				"--disable-pygtk",
#ifdef __ARM__
                "--disable-dbus",
#endif
				"--enable-compat-libdns_sd",
				"--with-distro=none"
      			],
			"sources": [
       				{
				"type": "archive",
				"url": "https://github.com/lathiat/avahi/releases/download/v0.7/avahi-0.7.tar.gz",
				"sha256": "57a99b5dfe7fdae794e3d1ee7a62973a368e91e414bd0dfa5d84434de5b14804"
        			}
			]
		},
		{
			"name": "libxml2",
			"cleanup": [ "/bin", "/share" ],
			"config-opts": [ "--without-python" ],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/GNOME/libxml2",
					"branch": "master"
				}
			]
		},
		{
			"name": "matio",
			"cleanup": [ "/bin", "/share" ],
			"config-opts": [ "" ],
			"build-commands": [ "true"],
			"sources": [
				{
					"type": "archive",
					"url": "https://github.com/tbeu/matio/releases/download/v1.5.12/matio-1.5.12.tar.gz",
					"sha1": "cb05a4a9a3af992890237b3f7a87f01cd8819528"
				}
			]
		},
		{
			"name": "libfftw3",
			"config-opts": [
				"--enable-shared",
				"--disable-static",
				"--enable-threads",
                "--enable-single"
#ifdef __X86__
                ,"--enable-float",
                "--enable-sse2",
                "--enable-avx",
				"--enable-openmp"
#endif
			],
			"sources": [
			        {
					"type": "archive",
					"url": "http://swdownloads.analog.com/cse/scopydeps/fftw-3.3.8.tar.gz",
					"sha256": "6113262f6e92c5bd474f2875fa1b01054c4ad5040f6b0da7c03c98821d9ae303"
				}
			]
		},
		{
			"name": "python3-mako",
			"buildsystem": "simple",
			"build-commands": [
				"pip3 install --no-index --find-links=\"file://${PWD}\" --prefix=/app mako"
			],
			"sources": [
				{
					"type": "file",
					"url": "https://files.pythonhosted.org/packages/b9/2e/64db92e53b86efccfaea71321f597fa2e1b2bd3853d8ce658568f7a13094/MarkupSafe-1.1.1.tar.gz",
					"sha256": "29872e92839765e546828bb7754a68c418d927cd064fd4708fab9fe9c8bb116b"
				},
				{
					"type": "file",
					"url": "https://files.pythonhosted.org/packages/28/03/329b21f00243fc2d3815399413845dbbfb0745cff38a29d3597e97f8be58/Mako-1.1.1.tar.gz",
					"sha256": "2984a6733e1d472796ceef37ad48c26f4a984bb18119bb2dbc37a44d8f6e75a4"
				}
			],
			"cleanup": [ "*" ]
		},
		{
			"name": "libgmp",
			"config-opts": [ "--prefix=/app", "--enable-cxx",
		    EXPAND(CFLAGS)
#ifdef __ARM__
            ,EXPAND(ASFLAGS)
#endif
            ],
			"sources": [
				{
					"type": "archive",
					"url": "https://ftp.gnu.org/gnu/gmp/gmp-6.2.0.tar.bz2",
					"sha256": "f51c99cb114deb21a60075ffb494c1a210eb9d7cb729ed042ddb7de9534451ea"
				}
			]
		},
		{
			"name": "liborc",
			"config-opts": [ "--prefix=/app"
#ifdef __ARM__
            ,EXPAND(CFLAGS) ,EXPAND(ASFLAGS) 
#endif
            ],
			"sources": [
				{
					"type": "archive",
					"url": "https://gstreamer.freedesktop.org/data/src/orc/orc-0.4.28.tar.xz",
					"sha256": "bfcd7c6563b05672386c4eedfc4c0d4a0a12b4b4775b74ec6deb88fc2bcd83ce"
				}
			]
		},
#ifdef __ARM__
		{
			"name": "libvolk",
			"cleanup": [ "/bin", "/share" ],
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [
            "-DCMAKE_INSTALL_PREFIX:PATH=/app",
            EXPAND(CMAKE_C_FLAGS), EXPAND(CMAKE_ASM_FLAGS)
			],
			"sources": [
				{
					"type": "archive",
					"url": "https://swdownloads.analog.com/cse/scopydeps/volk-2.4.1.tar.gz",
					"sha256": "61d681f90e0f30894f806ab050e9ba28260799c01f1ed0f58623942d8c7f4d48"
				}
			]
		},
#endif
		{
			"name": "gnuradio",
			"cleanup": [ "/bin", "/share" ],
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [
				"-DCMAKE_INSTALL_PREFIX:PATH=/app",
				"-DENABLE_GNURADIO_RUNTIME=ON",
				"-DENABLE_GR_ANALOG=ON",
				"-DENABLE_GR_BLOCKS=ON",
				"-DENABLE_GR_FFT=ON",
				"-DENABLE_GR_FILTER=ON",
				"-DENABLE_GR_DIGITAL:BOOL=OFF",
				"-DENABLE_GR_DTV:BOOL=OFF",
				"-DENABLE_GR_AUDIO:BOOL=OFF",
				"-DENABLE_GR_CHANNELS:BOOL=OFF",
				"-DENABLE_GR_TRELLIS:BOOL=OFF",
				"-DENABLE_GR_VOCODER:BOOL=OFF",
				"-DENABLE_GR_FEC:BOOL=OFF",
				"-DENABLE_SPHINX:BOOL=OFF",
				"-DENABLE_DOXYGEN:BOOL=OFF",
                EXPAND(DENABLE_INTERNAL_VOLK),
                EXPAND(CMAKE_C_FLAGS)
#ifdef __ARM__
                , EXPAND(CMAKE_ASM_FLAGS)
#endif
			],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/gnuradio",
					"branch": "scopy"
				}
			]
		},
		{
			"name": "libiio",
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [
				"-DCMAKE_INSTALL_PREFIX:PATH=/app",
				"-DCMAKE_INSTALL_LIBDIR:STRING=lib",
				"-DINSTALL_UDEV_RULE:BOOL=OFF",
				"-DWITH_TESTS:BOOL=OFF",
				"-DWITH_DOC:BOOL=OFF",
				"-DHAVE_DNS_SD:BOOL=OFF",
				"-DWITH_IIOD:BOOL=OFF",
				"-DWITH_LOCAL_BACKEND:BOOL=OFF",
				"-DWITH_MATLAB_BINDINGS_API:BOOL=OFF"
			],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/libiio",
					"commit": "0ed18cd8f6b2fac5204a99e38922bea73f1f778c"
				}
			]
		},
		{
			"name": "libtinyiiod",
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [
				"-DCMAKE_INSTALL_PREFIX:PATH=/app",
				"-DBUILD_SHARED_LIBS=OFF",
				"-DBUILD_EXAMPLES=OFF"
			],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/libtinyiiod"
				}
			]
		},
		{
			"name": "glog",
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [
				"-DCMAKE_INSTALL_PREFIX:PATH=/app",
				"-DWITH_GFLAGS=OFF"
			],
			"sources": [
				{
					"type": "git",
					"commit": "17e7679fd9beb95277ccd0708056ba85363f892b" ,
					"url": "https://github.com/google/glog"
				}
			]
		},
		{
			"name": "libad9361",
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [ "-DCMAKE_INSTALL_PREFIX:PATH=/app" ],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/libad9361-iio"
				}
			]
		},
        {
			"name": "gr-iio",
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [ "-DCMAKE_INSTALL_PREFIX:PATH=/app", "-DCMAKE_BUILD_TYPE=Release" ],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/gr-iio",
					"branch": "upgrade-3.8"
				}
			]
		},
		{
			"name": "libm2k",
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [
				"-DCMAKE_INSTALL_PREFIX:PATH=/app",
				"-DENABLE_PYTHON=OFF",
				"-DENABLE_CSHARP=OFF",
				"-DENABLE_LOG=ON" ,
				"--debug-find"
			],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/libm2k",
					"branch": "master"
				}
			]
		},
		{
			"name": "gr-m2k",
			"cleanup": [ "/share" ],
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [ "-DCMAKE_INSTALL_PREFIX:PATH=/app" ],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/gr-m2k"
				}
			]
		},
		{
			"name": "gr-scopy",
			"cleanup": [ "/share" ],
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [ "-DCMAKE_INSTALL_PREFIX:PATH=/app" ],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/gr-scopy"
				}
			]
		},
		{
			"name": "qwt",
			"cleanup": [ "/features", "/plugins", "/share" ],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/cseci/qwt",
					"branch": "qwt-multiaxes"
				},
				{
					"type": "script",
					"commands": [
						"sed -i \"s/^\\s*QWT_INSTALL_PREFIX.*$/QWT_INSTALL_PREFIX=\\/app/g\" qwtconfig.pri",
						"qmake"
					],
					"dest-filename": "configure"
				}
			]
		},
		{
			"name": "libzip",
			"cleanup": [ "/bin", "/share" ],
			"sources": [
				{
					"type": "archive",
					"url": "https://nih.at/libzip/libzip-1.1.3.tar.xz",
					"sha256": "729a295a59a9fd6e5b9fe9fd291d36ae391a9d2be0b0824510a214cfaa05ceee"
				}
			]
		},
		{
			"name": "sigrokdecode",
			"builddir": false,
			"buildsystem": "autotools",
			"config-opts": [ "--prefix=/app" ],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/sigrokproject/libsigrokdecode"
				}
			]
		},
		{
			"name": "iio-emu",
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [ "-DCMAKE_INSTALL_PREFIX:PATH=/app" ],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/iio-emu"
				}
			]
		},
#if 0
		{
			"name": "qtadvanceddocking",
			"builddir": true,
			"config-opts": [ "-DCMAKE_INSTALL_PREFIX:PATH=/app" ],
			"buildsystem": "cmake",
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/githubuser0xFFFF/Qt-Advanced-Docking-System",
					"tag": "3.8.1"
				}
			]
		},
#endif
		{
			"name": "scopy",
			"builddir": true,
			"buildsystem": "cmake",
			"config-opts": [ "-DCMAKE_INSTALL_PREFIX:PATH=/app", "-DCMAKE_PREFIX_PATH=/app/lib/pkgconfig;/app/lib/cmake", "-DWITH_DOC=OFF", "-DCMAKE_BUILD_TYPE=Release", "-DBREAKPAD_HANDLER=OFF", "-DWITH_NATIVEDIALOGS=OFF", "-DCLONE_IIO_EMU=OFF"],
			"sources": [
				{
					"type": "git",
					"url": "https://github.com/analogdevicesinc/scopy",
					"branch": "port-qwt"
				}
			]
		}
	]
}
