#include<iostream>
#include<algorithm>
namespace test{
    int n;
    long long m;
    long long a[500005];
    long long nowval;
    int ans=0;
    void main(){
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin>>n>>m;
        for(int i=1;i<=n;++i)std::cin>>a[i];
        std::sort(a+1,a+n+1);
        int l=1,r=1;
        while(r<=n){
            if(nowval+(a[r+1]-a[r])*(r-l+1)<=m)nowval+=(a[r+1]-a[r])*(r-l+1),++r;
            else nowval-=a[r]-a[l],++l;
            ans=std::max(ans,r-l+1);
            //std::cout<<l<<' '<<r<<'\n';
        }
        std::cout<<ans;
    }
}
int main(){test::main();return 0;}