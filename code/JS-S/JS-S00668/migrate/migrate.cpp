#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N=2e6+10;

int c,T;
int n,d;
int a[N],lft[N],rgt[N];

inline void subtaskA(){
    int ans=0,p=d/(a[2]-a[1]);
    for(int i=1;i<=n;i++){
        if(rgt[i]==i || lft[i]==i || rgt[i-1]!=rgt[i] || lft[i]!=lft[i-1]) continue;
        ans+=((i-1)/p)*((n-i)/p);
    }
    cout<<ans<<'\n';
    return ;
}

inline void subtaskB(){
    cout<<"0\n";
    return ;
}

inline void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) lft[i]=rgt[i]=i;
    int pos=0;
    for(int i=1;i<=n;i++){
        if(pos<i) pos=i;
        while(pos<n && a[pos+1]-a[i]<=d){
            ++pos;
            lft[pos]=min(lft[pos],i);
        }
        rgt[i]=pos;
    } 
    if(c==12 || c==11){
        subtaskA();
        return ;
    }
    if(c==13 || c==14){
        subtaskB();
        return ;
    }
    return ;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--) solve();
    return 0;
}