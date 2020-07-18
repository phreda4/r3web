/home/phr/emsdk/upstream/emscripten/em++ -O3 -s USE_SDL=2 -s USE_SDL_MIXER=2 graf.cpp -o graf.bc
/home/phr/emsdk/upstream/emscripten/em++ -O3 -s USE_SDL=2 -s USE_SDL_MIXER=2 r3s.cpp -o r3s.bc
/home/phr/emsdk/upstream/emscripten/em++ -O3 -s USE_SDL=2 -s USE_SDL_MIXER=2 r3s.bc graf.bc  --preload-file main.r3  -o r3web2.html

