#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int n,m;
int a[N],f[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000){
        cout<<n<<endl;
        return ;
    }
    sort(a+1,a+1+n);
    f[1]=1;
    int cn=m;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]<=cn){
            cn=m;
            f[i]=1;
            for(int j=i-1;j>0;j--){
                cn-=(a[i]-a[j]);
                f[i]++;
                if(cn<0){
                    cn+=(a[i]-a[j]);
                    f[i]--;
                    break;
                }
            }
        }else{
            cn=m;
            f[i]=1;
        }
    }
    int ans=-2147483648;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}