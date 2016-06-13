# qlldb

## What is it

Soon to be cross-platform UI for lldb in Qt.

In early prototype stages right now. Version 0.1 will be
* A GUI with most of the CLI functionality
* OS X only (but should be simply portable to Linux)

Next versions will actually exploit this being a GUI.

## Dependencies
- qt5
- cmake

## How to build
- `git clone https://github.com/projedi/qlldb.git`
- `cd qlldb`
- `git submodule update --init`
- `make configure` (invokes `cmake` under the hood)
- `cmake --build out`

## llvm version bump checklist
1. Merge changes in `third_party/lldb/tools/driver` to `src/driver`.

## Design (for some definition of "design") decisions

1. Command line replicates lldb.
2. CLI-style interaction is first class.
4. Boundaries: dynamic and small-scale static analysis tool. Won't grow into an IDE or even a text editor.
5. Logic that requires unit tests should be upstreamed.
6. Using chromium code style because of my personal familiarity with it.
7. Private lldb API usage is allowed if public API is not sufficient (but should try to extend public API and upstream it).
