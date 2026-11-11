#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n;
struct node{
    ll t;
    char c;
} a[N];
deque<node> d;
ll ans;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].t >> a[i].c;
    d.push_back(a[1]);
    for(int i = 2; i <= n; i++){
        if(a[i].c == a[i - 1].c)
            d[d.size() - 1].t += a[i].t;
        else
            d.push_back(a[i]);
    }
    while(d.size() > 1){
        ll mc = min(d.front().t, d.back().t);
        d[0].t -= mc;
        d[d.size() - 1].t -= mc;
        if(d.front().c != d.back().c)
            ans += mc;
        if(d.front().t == 0)
            d.pop_front();
        if(d.back().t == 0)
            d.pop_back();
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}