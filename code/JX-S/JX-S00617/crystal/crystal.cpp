#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ull m;
    scanf("%d %llu",&n,&m);
    ll a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    ull sum=0;
    ull ma=a[0],m0;
    int cnt=1,ans=1;
    for(int i=1;i<n;i++){
        m0=a[i]-ma;
        sum+=cnt*m0;
        ma=a[i];
        cnt++;
        if(sum<=m){
            ans=max(ans,cnt);
        }
        else{
            for(int j=i-cnt+1;sum>m;j++){
                sum-=ma-a[j];
                cnt--;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
