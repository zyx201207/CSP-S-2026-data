#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
                 (__) 
                 (oo) 
           /------\/ 
          / |    ||   
         *  /\---/\ 
            ~~   ~~   
..."Have you mooed today?"...
*/
int n,m,a[500010];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    bool s=true;
    int t=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=t){
            s=false;
            break;
        }
    }
    if(s){
        int d=a[2]-a[1];
        m/=d;
        int i=1;
        while(m-i>=0&&i<n){
            m-=i;
            i++;
        }
        cout<<i;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int c=a[i];
        int cur=m;
        int curans=1;
        int idx=i-1;
        while(cur-(a[i]-a[idx])>=0&&idx>=1){
            cur-=a[i]-a[idx];
            curans++;
            idx--;
        }
        ans=max(curans,ans);
    }
    cout<<ans;
}