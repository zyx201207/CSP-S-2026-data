#include<bits/stdc++.h>
using namespace std;
const int N=500005;
#define ll long long
int n,a[N],ans;
ll sum[N],m;
int check(int x){
    int l=1,r=x;
    while(l<r){
        int mid=(l+r)/2;
        ll num1=sum[x]-sum[mid-1]+m,num2=(x-mid+1ll)*a[x];
        if(num1>=num2)r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int k=check(i);
        ans=max(ans,i-k+1);
    }
    cout<<ans<<endl;
}