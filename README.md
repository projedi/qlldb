# qlldb

## A long list of something

* Deps in tree (potential optimization for test agents - allow external deps)
* chromium code style (familiarity) + clang-format
* can use private lldb API if needs be
* command line replicates lldb
* ui has input exactly like lldb with autocompletion and output window
* if keyboard shortcuts then replicate Visual Studio 
* this is dynamic (and static?) analysis tool. So expect for those integrations to land.
* windows for breakpoints, locals, threads, watchpoints, stacktrace
* window for source code with syntax highlighting, breakpoints, info-by-hover and without editing
* remote debugging (like gdbserver?)
* expose as lldbserver(?) for editors to speak directly to you.
* build a sample program, run lldb commands, expect controls in a certain state: mainly text content 
* Logic that requires unit tests should be upstreamed.

## Dependencies
- qt5
- doxygen
- swig

## Stuff to do
- `git clone …`
- `cd …`
- `git submodule update --init`
- `make configure`
- `make build`

## llvm version bump checklist
[ ] merge changes in `lldb/tools/driver` to `src/driver`.
