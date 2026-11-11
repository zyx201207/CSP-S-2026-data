#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10ll;
int a[N];
int c[N];
int len[N][2ll];
int n;

int tofind(int i){
    for(int j=1ll;j<=n;j++){
        if(i<=len[j][1ll] and i>=len[j][0ll]){
            return c[j];
        }
    }
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    len[1][0]=1ll;
    for(int i=1ll;i<=n;i++){
        char t;
        cin>>a[i]>>t;
        c[i]=t-'a'+1ll;
        if(i!=1ll)len[i][0ll]=len[i-1ll][0ll]+a[i-1ll];
        len[i][1ll]=len[i-1ll][1ll]+a[i];

    }
    int ans=0ll;
    int t=len[n][1ll]/2ll+1ll;
    //if(len[n][1ll]%2ll==1ll) t++;
    for(int i=t;i<=len[n][1ll];i++){
        if(tofind(i)!=tofind(len[n][1ll]+1ll-i)) {
            ans++;

        }
        //cout<<i<<" ";
    }
    cout<<ans;
    return 0;
}
