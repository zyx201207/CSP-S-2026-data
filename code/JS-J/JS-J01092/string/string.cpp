#include<bits/stdc++.h>
using namespace std;
int n,a[200009],cnt[29];
char c[200009];
long long ans=0,sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i],&c[i]);
        sum=sum+1ll*a[i];
    }ans=0;
    int l=1,r=n,tmp=0;
    while(l<r){
        tmp+=min(a[l],a[r]);
        if(c[l]==c[r]){
            if(a[l]==a[r]){
                l++;
                r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }else{
                a[l]-=a[r];
                r--;
            }
        }else{
            if(a[l]==a[r]){
                ans+=a[l];
                l++;
                r--;
            }else if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }else{
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
        }
    }printf("%lld",ans);
    return 0;
}
