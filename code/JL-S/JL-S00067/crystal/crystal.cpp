#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,r=0;
    char c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return r*f;
}
int n,a[500005],m,sum[500005];
bool check(int mid){
    for(int i=mid;i<=n;i++){
        if(sum[i]-sum[i-mid]+m>=a[i]*mid) return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1]+a[i];
    }
    int l=1,r=n,mid,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
