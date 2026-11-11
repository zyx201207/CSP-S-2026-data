#include<bits/stdc++.h>
#define pcr(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rcp(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+3;
const ll inf=1e9;
const int mod=998244353;
int n;
ll a[N],ans;
char ch[N];
void solve(){
    cin>>n;
    pcr(i,1,n,1) cin>>a[i]>>ch[i];
    int i=1,j=n;
    ll tmp=0;
    while(i<=j){
        if(tmp>0&&ch[i]!=ch[j+1]) ans+=min(tmp,a[i]);
        while(tmp<a[i]){
            tmp+=a[j];
            if(ch[i]!=ch[j]){
                if(tmp<=a[i]) ans+=a[j];
                else ans+=min(a[i]+a[j]-tmp,a[j]);
            }
            j--;
        }
        tmp-=a[i];
        i++;
    }
    cout<<ans;
    return;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    T=1;
    while(T--) solve();
    return 0;
}
