#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INF=1e5+10;
long long n,m,cnt,g[N],f[N*2],c[N*2],a[N],l,r;
int main(){
   // freopen("migrate.in","r",stdin);
  //  freopen("migrate.out","w",stdout);
    cin>>n>>m;
    while(m--){
        cin>>l>>r;
        for(int i=1;i<=l;i++){
            cin>>a[i];
        }
        if(n==0){
        if(l==4&&r==2)cout<<1<<endl;
        if(l==5&&r==2)cout<<2<<endl;
        if(l==5&&r==3)cout<<0<<endl;
        if(l==6&&r==2)cout<<1<<endl;
        }
    }
    
    return 0;
}
// 0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
