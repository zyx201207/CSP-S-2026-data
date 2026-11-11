#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3002;
int p[N],f[N],mn[N],s[N];
ll a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        ll d;
        int n,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) p[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
        for(int i=1;i<=n;i++){
            int pos;
            mn[i]=s[i-1]=0,f[i]=s[i]=1;
            for(int j=i+1;j<=n;j++){
                int pre=max(p[j],i);
                if(pre==j) break;
                if(mn[pre]!=mn[j-1]){
                    f[j]=min(3,s[pos]-s[pre-1]);
                    mn[j]=mn[j-1];
                }
                else{
                    f[j]=min(3,s[j-1]-s[pre-1]);
                    pos=j-1,mn[j]=mn[j-1]+1;
                }
                s[j]=s[j-1]+f[j],ans+=(f[j]==2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}