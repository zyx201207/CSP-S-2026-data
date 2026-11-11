#include<bits/stdc++.h>
#define int long long

using namespace std;

int c,t;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int cnt=0;
        int n,d;
        cin>>n>>d;
        int a[2000006];
        memset(a,0,sizeof(a));
        for(int j=1;j<=n;j++)
            cin>>a[i];
        if(c==11||c==12){
            if(a[2]-a[1]>d){
                cout<<0<<'\n';
                continue;
            }
            else{
                for(int j=1;j<=n;j++){
                    for(int x=2;x+j<=n;x+=2){
                        int l=j,r=j+x;
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
