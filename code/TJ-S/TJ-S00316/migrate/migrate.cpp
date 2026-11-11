#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;

int c;
int t;

int n;
long long d;
long long x[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    int cnt;
    bool vis;
    int ans;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n<=3){
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(x[j]-x[i]<=d){
                    continue;
                }
                cnt=0;
                vis=false;
                for(int k=i+1;k<j;k++){
                    if(vis){
                        if(x[j]-x[k]>d||x[k]-x[i]>d){
                            break;
                        }
                    }
                    if(x[j]-x[k]<=d&&x[k]-x[i]<=d){
                        vis=true;
                        cnt++;
                    }
                    if(cnt>2){
                        break;
                    }
                }
                if(cnt==2){
                    ans++;
                }
                //cout<<i<<" "<<j<<" "<<cnt<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
