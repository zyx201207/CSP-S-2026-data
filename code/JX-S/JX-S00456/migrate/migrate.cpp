#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int,int> s;
int x[2000011],c,t,n,d,ans;
bool b[2000011];

inline void read(int &x){
    char c=getchar();
    int s=1;
    while(c<'0'||c>'9'){
        if(c=='-')
            s*=-1;
        c=getchar();
    }
    x=0;
    while(c>='0'&&c<='9')
        x=(x<<1)+(x<<3)+c-48,
        c=getchar();
    x*=s;
    return;
}

inline void dfs(int p,int t,int ds){
    if(p==t){
        s[ds]++;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!b[i]&&abs(x[i]-x[p])<=d)
            b[i]=1,
            dfs(i,t,ds+1),
            b[i]=0;
    return;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(c),read(t);
    for(;t--;){
        read(n),read(d);
        for(int i=1;i<=n;i++)
            read(x[i]);
        ans=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                s.clear(),
                dfs(i,j,0),
                ans+=!s.empty()&&s.begin()->second==2;
        cout<<ans<<'\n';
    }
    return 0;
}
