#! /bin/bash
selfpath=$(cd "$(dirname "$0")"; pwd) 
echo $selfpath 

if [ -d "build" ]; then
  echo "Dirtionary build exists, Ready to delete build."
  rm -rf ./build
  mkdir build
fi

cd build

cmake ..
make


