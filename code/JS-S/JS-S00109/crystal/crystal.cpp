#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll a[N];
__int128 dis[N],s[N];
int n;
ll m;
bool ok=true;
bool ok2=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)ok=false;
    }
    ll xxx=(a[2]-a[1]);
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=xxx)ok2=false;
    }
    if(ok){
        ll ans=0;
        bool f=true;
        for(int i=1;i<=n-1;i++){
            if(ans+i<=m){
                ans+=i;
            }else{
                f=false;
                cout<<i<<endl;
                break;
            }
        }
        if(f)cout<<n<<endl;
        return 0;
    }
    if(ok2){
        __int128 ans=0;
        bool f=true;
        for(int i=1;i<=n-1;i++){
            if(ans+(__int128)(i*xxx)<=m){
                ans+=(__int128)(i*xxx);
            }else{
                f=false;
                cout<<i<<endl;
                break;
            }
        }
        if(f)cout<<n<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    __int128 x=a[n];
    for(int i=1;i<=n;i++)dis[i]=x-a[i];
    s[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+dis[i];
    }
    for(int i=n;i>=1;i--){
        s[i]=s[i]-(__int128)(dis[i]*(__int128)i);
        if(s[i]<=m){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
