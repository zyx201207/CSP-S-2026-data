#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
using ll=long long;
int c,t,n;
int d;
int x[MAXN];
int ans[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    cin>>c>>t;
//if(c==11||c==12){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }

        int gapx=abs(x[2]-x[1]);
        int gap=d/gapx;
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=gap-1;j++){
                if(i+gap+j<=n){
                    ans[i]++;
                }

            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            res+=ans[i];
        }
        cout<<res<<endl;
    }
  //  }

    return 0;
}
