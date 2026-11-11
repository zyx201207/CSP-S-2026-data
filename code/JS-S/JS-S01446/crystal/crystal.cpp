#include<bits/stdc++.h>
using namespace std;
#define int long long
bool dc=true;
int n,m;
int a[500005],d[500005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=a[i]-a[i-1];
        if(i>2&&d[i]!=d[i-1]) dc=false;
    }
    if(dc==true){
        int x=0,c=d[2],t=1;
        while(m>=x+t*c){
            x+=t*c;
            t++;
            if(t==n) break;
        }
        cout<<t;
        return 0;
    }
    return 0;
}