#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t lll;
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>

#define FILENAME "crystal"

ll read() {
    char ch=getchar_unlocked(); bool f=0; ll ret=0;
    while(ch<'0'||ch>'9') f=f||(ch=='-'),ch=getchar_unlocked();
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar_unlocked();
    return ret*(f?-1:1);
}

void write(ll v,char step='\n') {
    if(v<0) putchar_unlocked('-'),v=-v;
    if(v==0) putchar_unlocked('0');
    char s[30]; int tp=0;
    while(v) s[tp++]=v%10+'0',v/=10;
    while(tp--) putchar_unlocked(s[tp]);
    putchar_unlocked(step);
}

const int N=5e5+5;

int n,ans;
lll m,a[N],sumi,sumj;

void solve() {
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1,j=1;i<=n;i++) {
        sumi+=a[i];
        while(a[i]*(i-j+1)-(sumi-sumj)>m) sumj+=a[j++];
        ans=max(ans,i-j+1);
    }
    write(ans);
}

int main() {
    freopen(FILENAME".in","r",stdin);
    freopen(FILENAME".out","w",stdout);
    int T=1;
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    // cin>>T;
    ///////////////////////////////
    // T=read();
    while(T--) solve();
    return 0;
}

// g++ ./crystal.cpp -o ./crystal -O2 -std=c++14 -fsanitize=address,undefined -Wall -Wextra -Wconversion
