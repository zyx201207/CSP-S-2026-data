#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000001];
signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++)x[i]=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int dx=x[2]-x[1];
        if((d/dx)*2-1>n||d<=dx){
            cout<<0<<'\n';
        }else{
            cout<<n-(d/dx)*2+1<<'\n';
        }
    }
}