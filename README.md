
# LE-GAPI 

LE-GAPI is a Graphics API for low end devices. 
LE-GAPI stands for Low End - Graphics API (not entirely) but well, I (AR) don't have any good explaination in mind for why I call it LE-GAPI.
NOTICE: DEVELEOPMENT HAS BEEN STOPPED SO I (AR) CAN FOCUS ON MY HORROR GAME!
## Compiling locally:
To compile locally, clone the repo via git:
```bash
git clone https://github.com/2-LazyDevs/LE-GAPI.git
```
Then compile it using Microsoft Visual Studio Build Tools CL:
```bash
cl /EHsc src\*.c tests\main.c user32.lib gdi32.lib /I include
```
 The resulting output exe will be `le_context.exe`

NOTICE: THIS PROGRAM HAS BEEN ONLY COMPILED VIA CL (MS VS BUILD TOOLS) & HAS ONLY BEEN TESTED ON WINDOWS. IT ALSO DEPENDS ON WINDOW SPECIFIC LIBRARIES SUCH AS `windows.h`. CROSS-PLATFORM SUPPORT WILL BE ADDED IN THE FUTURE.

## API Reference

Right now, I don't have time to write this but will do soon.


## Contributing

Contributions are always welcome & are quite appreciated!

In order to contribute, you must agree to The 2LD OSL. Then, fork the repo, add your changes & make a pull request

## Authors

- [AR-DEV-1 of 2LD](https://github.com/AR-DEV-1)
- Nobody else, maybe you can be the first one?

## Acknowledgements

 - Godot for actually making me start this as my device is low end & Godot runs in compatibility.

 - [octokatherine's amazing readme creator](https://github.com/octokatherine/readme.so)

