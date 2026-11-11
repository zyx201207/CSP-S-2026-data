#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int c,t,n,b[2000005];
long long d,a[2000005],ans;
int f(long long x){
    int l=1,r=n,ans;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]<x)ans=mid,l=mid+1;
        else if(a[mid]==x)return mid;
        else r=mid-1;
    }
    return ans;
}
int solve(int l,int r){
    int cnt=0,sum=1;
    b[0]=l;
    while(b[cnt]<r){
        cnt++;
        b[cnt]=min(r,f(a[b[cnt-1]]+d));
    }
    for(int i=1;i<cnt;i++){
        if(a[b[i+1]]-a[b[i]-2]<=d){
            return 0;
        }
        if(a[b[i+1]]-a[b[i]-1]<=d){
            sum++;
        }
    }
    if(sum==2){return 1;}
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(j-i>=3)ans+=solve(i,j);
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
