#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+10;
int n;
int s[N];
char c[N];

int l=1,r,ll,rl,ans=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i]>>c[i];
    }
    r=n;
    ll=s[1];
    rl=s[n];
    while(l<r){
        if(ll<=rl){
            if(c[l]!=c[r]){
                ans+=ll;
            }
            rl-=ll;
            l++;
            ll=s[l];
        }else{
            if(c[l]!=c[r]){
                ans+=rl;
            }
            ll-=rl;
            r--;
            rl=s[r];
        }
    }
    cout<<ans<<endl;
    return 0;
}