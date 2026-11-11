#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long b[1000010];
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(n>5000){
        long long cha=a[2]-a[1];
        for(int i=1;i<=n;i++){
            b[i]=b[i-1]+i*cha;
        }
        for(int i=1;i<=n;i++){
            if(b[i]>m){
                printf("%d\n",i);
                return 0;
            }
        }
        printf("%d\n",n);
        return 0;
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        long long sum=0;
        int h=0;
        for(int j=i-1;j>=1;j--){
            sum+=a[i]-a[j];
            if(sum>m){
                ans=max(ans,i-j);
                h=1;
                break;
            }
        }
        if(h==0){
            ans=max(ans,i);
        }
    }
    printf("%d\n",ans);
    return 0;
}
