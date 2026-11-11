#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500015;
int n,m,a[MAXN],sum[MAXN];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    sum[0]=sum[1]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int left=1,right=1,Max=0;
    while(1){
        if(sum[right]-sum[left-1]+m>=a[right]*(right-left+1)){
            Max=max(Max,right-left+1);
            right++;
        }
        else left++;
        if(right>n)break;
    }
    cout<<Max;
    return 0;
}
