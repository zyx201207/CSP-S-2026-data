#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,cnt=0,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=5){
        if(n==1)cout<<1;
        else if(n==2){
            if(a[2]-a[1]<=m)cout<<2;
            else cout<<1;
        }else if(n==3){
            if(a[3]-a[1]<=m)cout<<3;
            else if(a[3]-a[2]<=m||a[2]-a[1]<=m)cout<<2;
            else cout<<1;
        }else if(n==4){
            if(a[3]-a[1]+a[4]-a[2]<=m)cout<<4;
            else if(a[4]-a[2]<=m||a[3]-a[1]<=m)cout<<3;
            else if(a[4]-a[3]<=m||a[3]-a[2]<=m||a[2]-a[1]<=m)cout<<2;
            else cout<<1;
        }else{
            if(a[5]-a[1]+a[4]-a[2]<=m)cout<<5;
            else if(a[4]-a[1]+a[3]-a[2]<=m||a[5]-a[2]+a[4]-a[3]<=m)cout<<4;
            else if(a[3]-a[1]<=m||a[4]-a[2]<=m||a[5]-a[3]<=m)cout<<3;
            else if(a[2]-a[1]<=m||a[3]-a[2]<=m||a[4]-a[3]<=m||a[5]-a[4]<=m)cout<<2;
            else cout<<1;
        }
    }else{
        int cha=a[2]-a[1];
        int ge=m/cha;
        for(int i=1;cnt<=ge;i++){
            if(i%2==0)cnt+=i/2;
            else cnt+=i/2+1;
            ans++;
        }
        cout<<min(ans,n);
    }
    return 0;
}

