[![Build Status](https://travis-ci.com/mmarkeloff/cpp-crtp-singleton.svg?branch=main)](https://travis-ci.com/mmarkeloff/cpp-crtp-singleton)

<h1 align="center">
cpp-crtp-singleton
</h1>

C++ header only library implements a thread-safe singleton class using CRTP.

## Usage

```cpp
#include <crtp_st.hpp>

class Derived : public crtp_st::Base<Derived> {
public:
    void impl() { }
};

int main(int argc, char* argv[]) {
    Derived::instance().impl();

    return 0;
}
```

## Examples

See [sample project](sample) for more complete usage examples.

## Documentation

See automatic generated [docs](https://mmarkeloff.github.io/cpp-crtp-singleton/) for more information.
