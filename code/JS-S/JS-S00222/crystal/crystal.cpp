#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500050;
int n,m,mx;
int a[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    bool flag1=true;bool flag2=true;
    int cha;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)flag1=false;
        if(i==2) cha=a[2]-a[1];
        else if(i>2&&a[i]!=a[i-1]+cha) flag2=false;
    }
    sort(a+1,a+1+n);
    if(flag2==true||flag1==true){
        m/=2;
        int sum=0;
        int ans;
        for(ans=0;sum<=m;ans++) sum+=ans;
        cout<<ans-1;
        return 0;
    }
    else{
        int ans=1;
        for(int i=n;i>=2;i--){
            int cnt=1;
            int sum=m;
            for(int j=i-1;j>=1;j--){
                if(sum<(a[i]-a[j]))break;
                sum-=(a[i]-a[j]);
                cnt++;
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }

    return 0;
}
