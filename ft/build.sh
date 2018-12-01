#! /bin/bash
selfpath=$(cd "$(dirname "$0")"; pwd) 
echo $selfpath 

if [ -d "build" ]; then
  echo "Dirtionary build exists, Ready to delete build."
  rm -rf ./build
  mkdir build
fi

cd build

echo "****************Build FT Project**********************"
cmake ..
make
echo "Build FT Project finished"

cd ../build

echo "*************Start Run Ft Test Cases*****************"
./FT


