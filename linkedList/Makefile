all:
	@mkdir -p .build

	cd .build && cmake .. 
	cd .build && $(MAKE)

clean:
	cd .build && $(MAKE) clean
	rm -rf .build
