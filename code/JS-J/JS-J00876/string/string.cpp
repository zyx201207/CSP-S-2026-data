#include <bits/stdc++.h>
using namespace std;
long long n,lc,rc,le,re;
long long len = 0;
struct cstr{
    long long a;
    char c;
}a[200005];
vector<cstr> lv,rv;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].a >> a[i].c;
        len += a[i].a;
    }
    le = len / 2,re = len - le + 1;
    long long lp = 1,rp = len,l = 1,r = n;
    while(lp <= le){
        lv.push_back({a[l].a,a[l].c});
        l++;
        lp += a[l].a;
    }
    while(rp >= re){
        rv.push_back({a[r].a,a[r].c});
        r--;
        rp -= a[r].a;
    }
    long long llen = 0,rlen = 0;
    for(int i = 1;i < l;i++){
        llen += a[i].a;
    }
    for(int i = n;i > r;i--){
        rlen += a[i].a;
    }
    if(le - llen + 1 != 0){
        lv.pop_back();
        lv.push_back({le - llen + 1,a[l].c});
    }
    if((len - rlen + 1) - re + 1 != 0){
        rv.pop_back();
        rv.push_back({(len - rlen + 1) - re + 1,a[r].c});
    }
    long long hf = le,ans = 0;
    while(!lv.empty() && !rv.empty()){
        long long x = min(lv[lv.size() - 1].a,rv[rv.size() - 1].a);
        if(lv[lv.size() - 1].c != rv[rv.size() - 1].c){
            ans += x;
        }
        lv[lv.size() - 1].a -= x;
        rv[rv.size() - 1].a -= x;
        if(lv[lv.size() - 1].a == 0){
            lv.pop_back();
        }
        if(rv[rv.size() - 1].a == 0){
            rv.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}
