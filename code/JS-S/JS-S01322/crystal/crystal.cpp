#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],pre[500005];
bool check(int x){
    int i=1,j=x;
    while(j<=n){
        long long sum=0;
        sum=a[j]*(x-1)-(pre[j-1]-pre[i-1]);
        if(sum<=m)return 1;
        else i++,j++;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
