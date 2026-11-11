#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],b[N],s[N];
bool check(int len){
    ll cnt,sum=0;
    for(int i=2;i<=len;i++)
        sum+=1ll*b[i]*(i-1);
    cnt=sum;
    for(int i=3;i<=n-len+2;i++){
        sum+=-s[i+len-3]+s[i-2]+1ll*b[i+len-2]*(len-1);
        cnt=min(cnt,sum);
    }
    return cnt<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        s[i]=s[i-1]+b[i];
    }
    int l=0,r=n,mid,ans;
    while(r>l){
        mid=(l+r)>>1;
        if(!check(mid))
            r=mid;
        else
            l=mid+1,ans=mid;
    }
    cout<<ans;
    return 0;
}
