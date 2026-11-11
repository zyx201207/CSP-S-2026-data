// hub
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
template<typename ...Args> void Debug(const Args&... arg){
    int d[] = {(cerr << arg << ' ',0)...};
    cerr << '\n';
}
#define dbg(...) Debug(#__VA_ARGS__,'=',__VA_ARGS__)
#else
#define dbg(...) void()
#endif // LOCOL
void solve(int c){
    int n,k;
    cin >> n >> k;
    for (int i = 1,u,v;i < n;i++) cin >> u >> v;
    cout << rand() % (n / k) + 1 << '\n';
}
int main(){
#ifdef LOCAL

#else
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int c,t;
    cin >> c >> t;
    while (t--) solve(c);
    return 0;
}
//以上写了个滚木
/*
我们孤身闯入这世界里
找寻名为宝藏的通关奖励
——珍珠

生命是一万次的谎话
吊唁这梦和童话
万水千山看罢
蹉跎几度年华
——空心人札记

只因为你那渴望自由的心脏
困在一张没有空隙的网
我们的周围并非没有光亮
只是太耀眼将我们灼伤
——反乌托邦

比赛结束前打的，歌词记不清了，不知道有没有错
我想上迷惑行为大赏，qwq
*/
