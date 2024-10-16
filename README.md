# wrap function

キーワード:

- c++
- emscripten
- clang
- wrapオプション
- cmake

## compile

```bash
rm -rf build_em && sh make.sh build_em
```

## run

```bash
node ./build_em/main.js
```

## 結果

```bash
❯ node ./build_em/main.js
Func start wrap foo.
Func foo.
Func wrapped.
```
