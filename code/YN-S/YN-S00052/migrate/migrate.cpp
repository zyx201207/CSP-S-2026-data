#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int c,t,n;
const int N=2e6+5;
ll d,x[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll ans=0;
        bool flag1=0;bool flag2=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=2;i<n;i++){
            if(x[i]-x[i-1]!=x[i+1]-x[i]) flag1=1;
            if(x[i]-x[1]<=d&&x[n]-x[i]<=d) flag2=1;
        }
        if(x[n]-x[1]<=d) cout<<0<<"\n";
        else if(flag1==0){
            ll del=x[2]-x[1];
            if(2*del<=d&&3*del>d) cout<<n-3<<"\n";
            else cout<<0<<"\n";
        }
        else if(n<=300){
            for(int i=1;i<=n;i++)
                cin>>x[i];
            for(int i=1;i<=n;i++){
                for(int j=i+2;j<=n;j++){
                    int cnt=0;
                    if(x[j]-x[i]<=d) continue;
                    for(int k=i;k<=j;k++){
                        if(x[k]-x[i]<=d&&x[j]-x[k]<=d)
                            cnt++;
                    }
                    if(cnt==2) ans++;
                }
            }
            cout<<ans<<"\n";
        }
        else cout<<0<<"\n";
    }
    return 0;
}
