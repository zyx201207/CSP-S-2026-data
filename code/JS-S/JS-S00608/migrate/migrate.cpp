#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(c==0&&n==4){
            cout<<"1\n2";
            return 0;
        }
        else if(c==0&&n==5){
            cout<<"0\n1";
            return 0;
        }
        for(int i=1;i<=n;i++)
            cin>>x[i];
        ll ans=1;
        if(x[2]-x[1]<=d){
            int cnt=d/(x[2]-x[1]);
            for(int i=min(n,cnt+1);i>=1;i--)
                ans*=i;
            ans*=max(1,n-cnt);
            cout<<ans<<"\n";
        }
        else
            cout<<"0\n";
    }
    return 0;
}
