#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(2e6+10)
#define int long long
int c,T,pos[MAXN];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        int n,d,flag=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>pos[i];
        for(int i=2;i<n;i++) 
            if((pos[i+1]-pos[i])!=(pos[2]-pos[1])){flag=0; break;}
        if(flag==1){
            int k=pos[2]-pos[1];
            if(d>=k*2&&(d<k*3)) cout<<n-3<<"\n";
            else cout<<0<<"\n";
            continue;
        }else{cout<<1<<"\n";}
    }return 0;
}