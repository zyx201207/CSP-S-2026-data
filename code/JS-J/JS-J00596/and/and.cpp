#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,cnt;
ll ans;
bool a[N][32],cun[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll t;
        cin>>t;
        for(int j=0;j<=30;j++){
            if(t%2){
                a[i][j]=1;
            }
            t/=2;
            //cout<<a[i][j]<<" ";
        }
        //cout<<"\n";
    }
    for(int i=30;i>=0;i--){
        cnt=0;
        for(int j=1;j<=n;j++){
            if(cun[j]==0&&a[j][i]==1){
                cnt++;
            }
        }
        if(cnt>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                if(a[j][i]==0){
                    cun[j]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
