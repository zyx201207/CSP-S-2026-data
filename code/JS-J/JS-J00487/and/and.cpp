#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans=-1,t;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
    }
    else if(m==2){
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,(a[i] & a[j]));
                
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++) ans &= a[i];
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            if(i==1){
                t=a[2];
                for(int j=2;j<=n;j++){
                    t&=a[j];
                }
                
            }
            else{
                t=a[1];
                for(int j=1;j<=n;j++){
                    if(j!=i) t&=a[j];
                }
            }
            ans=max(ans,t);
        }
    }
    else if(n<=20){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else ans=114514;
    printf("%lld",ans);
    return 0;
}
// Never mind