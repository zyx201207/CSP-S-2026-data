#include<iostream>
#include<algorithm>
#include<cmath>
const int N=5e5+10;
long long n,m,ans=1;
long long a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
        std::cin>>a[i];
    std::sort(a+1,a+1+n);
    if(n<=5000){
        for(int i=1;i<n;i++)
            d[i]=a[i+1]-a[i];
        for(long long i=1;i<n;i++){
            long long now=0;
            for(long long j=i;j<=n-1;j++)
                now+=d[j]*(j-i+1);
            for(long long j=n-1;j>=i;j--){
                if(now<=m){
                    ans=std::max(ans,j-i+2);
                    break;
                }
                now-=(j-i+1)*d[j];
            }
        }
        std::cout<<ans;
        return 0;
    }
    else{
        __int128 D=a[2]-a[1];
        __int128 k=m/D;
        __int128 s=sqrt(k<<1);
        s-=2;
        while(true){
            if((s-1)*(s)/2<=k) s++;
            else{
                s--;
                break;
            }
        }
        if(s>n) s=n;
        ans=s;
        std::cout<<ans;
        return 0;
    }
    return 0;
}