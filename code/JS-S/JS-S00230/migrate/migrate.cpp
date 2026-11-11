#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long x[20010];
long long ans;
pair<short,short> num[20010][20010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int qq=1;qq<=t;qq++){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            num[i][i].first=-1;
            num[i][i].second=0;
            for(int j=i+1;j<=n;j++){
                if((x[j]-x[i])<=d){
                    num[i][j].first=0;
                    num[i][j].second=1;
                }
                else{
                    num[i][j].first=20000;
                    num[i][j].second=0;
                }
            }
        }
        for(int len=2;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
                    if(1ll*num[i][k].first+1ll*num[k][j].first+1<1ll*num[i][j].first){
                        num[i][j].second=num[i][k].second*num[k][j].second;
                    }
                    else if(1ll*num[i][k].first+1ll*num[k][j].first+1==1ll*num[i][j].first){
                        num[i][j].second+=num[i][k].second*num[k][j].second;
                    }
                }
            }
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if(num[i][j].second==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
