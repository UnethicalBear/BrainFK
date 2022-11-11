# BrainFK
Open source Brainf**k interpeter using C++. CLI interface included. 

## CLI Interface Usage:

~$ BF [args]

### -h --help

Gives a help menu to explain how to use the system. Optionally, -h / --help [function] returns just the help for that option.

### -v --version
returns the version of the system

### -s --string
run brainf**k code from a string provided, e.g. 

```shell 
BF --string +--+[>>-<<>>]-

```

Note that there cannot be any spaces in the code.

### -f --file

run brainf**k code from a input file specified, e.g.

```shell
BF --file main.bf
```

will run the contents of the file ```main.bf``` .

## Download

Either:

- Download the code and compile for yourself (make sure to see liscneing)
- Go to the releases section (below about) to find the latest release
- Go to the releases folder to find a specific version of the compiler