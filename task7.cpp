#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include "Audiofile.h"
#include<array>
#include<pybind11/pybind11.h>
#include <pybind11/stl.h>
#include<pybind11/functional.h>
#include<pybind11/chrono.h>
#include<pybind11/complex.h>

using namespace std;
const int m=276858;
const int n=2;
std::array < array<double, m>, n> value(string path);
namespace py = pybind11;
std::array < array<double, m>, n> value(string path)
{
AudioFile<double> audioFile;
audioFile.load(path);
std::array < array<double,m>,n> samp;
for (int i = 0; i < audioFile.getNumSamplesPerChannel(); i++)
{
    for (int channel = 0; channel < audioFile.getNumChannels(); channel++)
    {
       samp[channel][i]=audioFile.samples[channel][i];
    }
}
int n=audioFile.getNumChannels();
cout<<n;
    return samp;
}
PYBIND11_MODULE(modulecpp3,mod){
    mod.def("value",&value);
}
