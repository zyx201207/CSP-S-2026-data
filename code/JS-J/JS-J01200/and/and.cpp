#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
bool b[200005][35];
int cnt1[35];
bitset<200005>tot[35],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int t=a[i],now=31;
        while(t){
            b[i][--now]=t&1;
            t>>=1;
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=30;j++)cout<<b[i][j];
        cout<<endl;
    }
    */
    for(int j=1;j<=30;j++){
        for(int i=1;i<=n;i++){
            if(b[i][j]==1)cnt1[j]++;
            tot[j][i-1]=b[i][j];
        }
    }
    //for(int i=1;i<=30;i++)cout<<cnt1[i]<<' '<<tot[i]<<endl;
    for(int j=1;j<=30;j++){
        if(cnt1[j]>=m&&ans==0){
            ans=tot[j];
            continue;
        }
        else if(cnt1[j]>=m){
            int dc=0;
            for(int i=1;i<=n;i++){
                if(ans[i-1]&1)if(b[i][j]==1){
                    dc++;
                    //cout<<i<<" "<<j<<" "<<ans<<endl;
                }
            }
            if(dc>=m)ans&=tot[j];
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(ans[i-1]&1){
            if(res==0)res=a[i];
            else res&=a[i];
        }
    }
    cout<<res;
    return 0;
}
