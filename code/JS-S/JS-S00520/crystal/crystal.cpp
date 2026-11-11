#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
int vis1=1,vis2=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int dc;
    vector<int>shui(n+1);
    for(int i=1;i<=n;i++){
        cin>>shui[i];
        if(i==2){
            dc=shui[i]-shui[i-1];
        }
        if(i>2&&vis1){
            if((shui[i]-shui[i-1])!=dc){
                vis1=0;
            }
        }
    }
    if(m==0){
        int ansz=0;
        for(int i=1;i<=n;i++){
            ansz=0;
            for(int j=i;j<=n;j++){
                if(shui[i]==shui[j]){
                    ansz++;
                }
            }
            ans=max(ans,ansz);
        }
        cout<<ans;
        return 0;
    }

    sort(shui.begin()+1,shui.end());
    if(vis1){
        int dang=1;
        int ansz=1;
        while(m){
            dc=dc*dang;
            m-=dc;
            dang++;
            if(m>=0) ansz++;
            if(m<dc*dang) break;
            if(ansz==n) break;
        }
        cout<<ansz;
        return 0;
    }

    for(int i=2;i<=n;i++){
        int ci=m;
        int ansz=1;
        for(int j=i-1;j>=1;j--){
            int cha=shui[i]-shui[j];
            if(ci<cha) break;
            ci-=cha;
            ansz++;
        }
        ans=max(ans,ansz);
    }
    cout<<ans;
    return 0;
}
