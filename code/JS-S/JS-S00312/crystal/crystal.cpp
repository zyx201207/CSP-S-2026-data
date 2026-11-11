#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],sum[N];
long long n,m,ans=0;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long len=j-i+1,tmp=sum[j]-sum[i-1]+m;
            if(tmp>=a[j]*len){
                ans=max(ans,len);
            }
        }
    }
    cout<<ans;
    return 0;
}
