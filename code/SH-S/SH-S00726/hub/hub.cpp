#include<bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define usize size_t
#define Vec vector
#define String string
#ifdef DEBUG
template<typename T>
T debug_impl(T value, String expr, i32 line) {
    cerr << "[" << line << "] " << expr << " = " << value << endl;
    return value;
}
#define dbg(x) debug_impl((x), #x, __LINE__)
#else
#define dbg(x)
#endif

i32 main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    fclose(stdin);
    fclose(stdout);
    return 0;
}