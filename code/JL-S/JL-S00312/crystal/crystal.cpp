#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int gongcha=1,zhi=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=i) zhi=0;
        if(i>=2){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                gongcha=0;
                break;
            }
            else gongcha=a[i]-a[i-1];
        }
    }
    if(zhi==1){
       cout<<floor(sqrt((2*m-0.75)+1)-0.5)+1;
    }
    else if(gongcha){
      cout<<floor(sqrt((2*m-0.75)*gongcha+1)-0.5*gongcha)+1;
    }
    else if(n<=5000){
        ll mx=-1;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]&&i!=1) continue;
            ll sum=0,cnt=0;
            for(int j=i;j>=1;j--){
                if(sum+(a[i]-a[j])>m) break;
                sum+=(a[i]-a[j]);
                cnt++;
            }
            for(int j=i+1;j<=n;j++){
                if(a[j]==a[i]) cnt++;
                else break;
            }
            mx=max(mx,cnt);
        }
        cout<<mx;
    }
    return 0;
}
