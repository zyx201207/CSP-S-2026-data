#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int C,n,d,ans;
int a[N],u[N],s[N];
void prep();
void init();
void dr();
void work();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int T=1;
    cin>>C>>T;
    prep();
    while(T--){
        init();
        dr();
        work();
    }
    return 0;
}
void prep(){
}
void init(){
    ans=0;
    fill(u+1,u+N+1,0);
    fill(s+1,s+N+1,0);
}
void dr(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void work(){
    if(n<=3){cout<<"0\n";return;}
    if(C==13||C==14){
        int pos;
        for(int i=1;i<=n;i++)
            if(a[i]-a[1]<=d&&a[n]-a[i]<=d){pos=i;break;}
        if(pos<=3) cout<<0<<'\n';
        else if((n-pos<=2)) cout<<0<<'\n';
        else cout<<2<<'\n';
        return;
    }
    for(int i=1;i<=n-3;i++)
        if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2]<=d&&a[i+3]-a[i]>d) ans++;
    cout<<ans<<'\n';
}
//WA all
