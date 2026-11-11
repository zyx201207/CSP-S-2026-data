#include<bits/stdc++.h>
using namespace std;
long long a[500005],m;
long long su[500005];
int n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        su[i]=su[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,res=i;
        while(l<=r){
            int mid=l+r>>1;
            if(m>=a[i]*(i-mid+1)-(su[i]-su[mid-1])){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-res+1);
    }
    printf("%d",ans);
    return 0;
}