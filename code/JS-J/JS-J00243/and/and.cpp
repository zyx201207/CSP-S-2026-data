#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int use[N],a[N];
int m,n;
int ans=0;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) use[i]=1;
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            int cur=a[j]&(1<<i);
            //cout<<cur<<" "<<use[j]<<" ";
            if(cur>0 && use[j]==1) cnt++;
        }
        //cout<<cnt<<" ";
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                int cur=a[j]&(1<<i);
                if(cur==0) use[j]=0;
            }
            ans+=(1<<i);
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
