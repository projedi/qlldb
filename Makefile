.PHONY: all build configure clean run

all: build

configure:
	mkdir -p out
	# CMAKE_PREFIX_PATH is a hack for OS X.
	cd out && CMAKE_PREFIX_PATH=/usr/local/opt/qt5 cmake ..

build:
	cmake --build out --target qlldb -- -k -j9

clean:
	rm -rf out/

run: build
	out/src/qlldb
