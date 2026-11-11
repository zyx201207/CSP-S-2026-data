#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int b[200005][105];
int cnt[105];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i],p=0;
//        cout<<i<<"-------\n";
        for(;x;x/=2,p++){
//            cout<<x<<" ";
            if(x%2==1){
                b[i][p]=1;
                cnt[p]++;
            }
        }
//            cout<<endl;
    }
    int ans=0;
    for(int p=30;p>=0;p--){
        if(cnt[p]>=m){
            ans+=(1<<p);
            for(int i=1;i<=n;i++){
                if(b[i][p]==0&&a[i]!=-1){
                    a[i]=-1;
                    for(int t=0;t<=30;t++){
                        cnt[t]-=b[i][t];
                    }
                }
            }
            //cout<<p<<"------------\n";
            //for(int i=0;i<=3;i++){
            //    cout<<i<<":"<<cnt[i]<<' ';
            //}
            //cout<<endl;
        }
    }
    cout<<ans;
    return 0;
}
