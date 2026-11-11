#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x[2000007],ans;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        long long dis;
        for(long A=1;A<n;A++){
            for(long B=A+1;B<=n;B++){
                dis=x[B]-x[A];
                if(dis>d && dis<2*d){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }

    return 0;
}
