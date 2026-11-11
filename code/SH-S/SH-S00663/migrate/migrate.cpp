#include <bits/stdc++.h>
using namespace std;
long long m[2000005];
void solve(){
    long long n,d,x,y,ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }

    int cnt=0;
    for(int i=1;i<=n-2;i++){
        for(int j=i+2;j<=n;j++){
            int cnt=0;
            for(int k=i+1;k<j;k++){
                if(m[k]-m[i]>d)
                    break;
                if(m[j]-m[k]<=d)
                    cnt++;
            }
            if(cnt==2&&!(m[j]-m[i]<=d))
                ans++;
        }
    }

    cout<<ans<<endl;

}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }

}
