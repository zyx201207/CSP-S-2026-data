#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN];
long long n,m;
bool cmp(long long a,long long b){
    return a<b;
}
long long sum[MAXN];
int ans=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        for(int j=1;j<=i;j++){
            if(a[i]*(i-j+1)-sum[i]+sum[j-1]<=m){
                ans=max(ans,i-j+1);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
