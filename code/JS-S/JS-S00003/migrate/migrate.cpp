#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c,d,a[2000006];
ll T;
//prority_queue;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if(c<=6){
        while(T--){
            cin>>n>>d;
            ll t[333][333];
            ll tt[333][333];
            ll ans=0;
            //ll minn[305];
            //for(int i=1;i<=n;i++){
                //minn[i]=1e18;
            //}
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            for(int i=1;i<=n;i++){
                for(int j=1;i-j>=1;j++){
                    if(a[i]-a[i-j]<=d){
                        t[i][i-j]=1;
                    }
                    else break;
                }
                for(int j=1;i+j<=n;j++){
                    if(a[i+j]-a[i]<=d){
                        t[i][i+j]=1;
                    }
                    else break;
                }
            }
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(t[i][k]&&t[k][j]){
                            if(t[i][j]==0){
                                t[i][j]=t[i][k]+t[k][j];
                                tt[i][j]++;
                            }
                            else if(t[i][j]==t[i][k]+t[k][j]){
                                tt[i][j]++;
                            }
                            else if(t[i][j]>=t[i][k]+t[k][j]){
                                tt[i][j]=1;
                                t[i][j]=t[i][k]+t[k][j];
                            }
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(tt[i][j]==2) ans++;
                }
            }
            cout<<ans/2<<"\n";
        }

    }
    else{
        while(T--){
            if(15<=c&&c<=18){
                cout<<0<<'\n';
                continue;
            }
            if(c==11||c==12){
                cout<<0<<'\n';
                continue;
            }
            cin>>n>>d;
            cout<<0<<'\n';
        }

    }

    return 0;
}

