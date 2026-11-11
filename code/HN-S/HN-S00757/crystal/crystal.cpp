#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int> 
#define popc __builtin_popcount
#define All(v) (v).begin(),(v).end()
#define lowbit(x) ((x)&(-(x)))
const int N=5e5+5;
int n,a[N],m;
inline int read(){
    int x(0),t(0);
    static char ch=getchar();
    while(!isdigit(ch)) t|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?-x:x;
}
int s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int res=1;
    for(int i=1,j=1;i<=n;i++){
        while(a[i]*(i-j+1)-(s[i]-s[j-1])>m) j++;
        res=max(res,i-j+1);
    }
    cout<<res;
    return 0;
}
// Oct31==Dec25?