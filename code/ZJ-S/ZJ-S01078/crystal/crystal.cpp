#include<bits/stdc++.h>
using namespace std;typedef long long ll;
#define getchar getchar_unlocked
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
const int maxn=5e5+5;
int n;ll lim,a[maxn];
inline int read(){
    char c;int f=1;for(c=getchar();c<'0'||c>'9';c=getchar())c=='-'&&(f=-1,0);
    int res=0;for(;c>='0'&&c<='9';c=getchar())
        res=(res<<1)+(res<<3)+(c^48);
    return res*f;
}
inline ll lread(){
    char c;int f=1;for(c=getchar();c<'0'||c>'9';c=getchar())c=='-'&&(f=-1,0);
    ll res=0ll;for(;c>='0'&&c<='9';c=getchar())
        res=(res<<1)+(res<<3)+(c^48);
    return res*f;
}
int main(){open(crystal);
    n=read(),lim=lread();
    // cerr<<"111 "<<n<<'\n';
    for(int i=1;i<=n;i++)a[i]=lread();
    sort(a+1,a+n+1);int ans=0;for(int i=1,cnt=0,j=1,k=1;i<=n;i=j){
        lim-=(a[i]-a[i-1])*cnt;for(;j<=n&&a[j]==a[i];j++)cnt++;
        for(;k<i&&lim<0ll;lim+=(a[i]-a[k]),cnt--,k++);
        ans=max(ans,cnt);
    }printf("%d\n",ans);
    return 0;
}