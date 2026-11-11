#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool a[200005][35],erased[200005];
ll s[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,m,ans=0;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        for(int j=0;j<=29;j++){
            a[i][j]=(x&1);
            s[j]+=(x&1);
            x>>=1;
        }
    }
    for(int p=29;p>=0;p--){
        if(s[p]>=m){
            ans+=(1<<p);
            for(int i=1;i<=n;i++){
                if(!a[i][p]&&!erased[i]){
                    erased[i]=1;
                    for(int j=p-1;j>=0;j--){
                        s[j]-=a[i][j];
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
