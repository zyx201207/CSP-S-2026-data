#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

LL n,m;
LL a[500005];
LL diff[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        diff[i]=a[i]-a[i-1];
    }
    int l=1,r=1;
    LL sum=0,ans=0,cnt=1,temp=0;
    while(r<=n){
        if(sum<=m){
            ans=max(ans,cnt);
        }
        if(sum<=m){
            r++;
            temp+=diff[r];
            sum+=cnt*diff[r];
            cnt++;
        }else{
            sum-=temp;
            cnt--;
            temp-=diff[l];
            l++;
        }
    }
    cout << ans;
    return 0;
}
