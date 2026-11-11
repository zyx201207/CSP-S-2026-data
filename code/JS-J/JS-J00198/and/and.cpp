#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,mx,x,cnt;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20){
        for(int i=0;i<(1<<n);i++){
            x=i,cnt=0;
            while(x){
                cnt+=x&1;
                x>>=1;
            }
            if(cnt!=m)continue;
            ans=2147483647;
            for(int j=1;j<=n;j++){
                if((i>>(n-j))&1){
                    ans&=a[j];
                }
            }
            mx=(mx>ans?mx:ans);
        }
        cout<<mx;
        return 0;
    }
    if(m==1){
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    if(m==n){
        int ans=2147483647;
        for(int i=1;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==2&&n<=2000){
        int ans=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
    bool isA=true;
    for(int i=1;i<=n;i++){
        int x=a[i]+1;
        while(x%2==0)x/=2;
        if(x>1){
            isA=false;
            break;
        }
    }
    if(isA){
        sort(a+1,a+1+n,cmp);
        cout<<a[m];
        return 0;
    }
    bool isB=true;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=(i-1)){
            isB=false;
            break;
        }
    }
    int x=n;
    while(x%2==0)x/=2;
    if(isB&&x==1){
        int ans=2147483647;
        for(int i=n-1;i>=n-m;i--)ans&=i;
        cout<<ans;
        return 0;
    }
    int ans=2147483647;
    for(int i=n;i>=n-m+1;i--)ans&=a[i];
    cout<<ans;
    return 0;
}
