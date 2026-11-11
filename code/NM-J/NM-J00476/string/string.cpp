#include<bits/stdc++.h>
using namespace std;
int n,a[200009];
char c[200009];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>c[i];
    }
    for(int l=1,r=n;l<r;l++,r--){
        if(c[l]==c[r]){
            if(a[l]>=a[r]){
                if(c[r]!=c[r-1]){
                    ans+=a[l]-a[r];
                    a[r-1]-=a[l]-a[r];
                }
            }else{
                if(c[l]!=c[l+1]){
                    ans+=a[r]-a[l];
                    a[l+1]-=a[r]-a[l];
                }
            }
            continue;
        }
        //
        if(a[l]>=a[r]){
            if(c[r]!=c[r-1]){
                ans+=a[l];
                a[r-1]-=a[l]-a[r];
            }
        }else{
            if(c[l]!=c[l+1]){
                ans+=a[l];
                a[l+1]-=a[r]-a[l];
            }

        }
    }
    printf("%lld",ans);
    return 0;
}
