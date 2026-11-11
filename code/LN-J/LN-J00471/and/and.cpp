#include<iostream>
namespace test{
    int a[200005][35];
    int w[35];
    int n,m;
    void main(){
        freopen("and.in","r",stdin);
        freopen("and.out","w",stdout);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin>>n>>m;
        for(int i=1;i<=n;++i)std::cin>>a[i][29];
        int n1=n;
        for(int j=29;j>0;--j){
            int cnt=0,idx=0;
            for(int i=1;i<=n1;++i)if((1<<j)&a[i][j])cnt++;
            if(cnt>=m){for(int i=1;i<=n1;++i)if((1<<j)&a[i][j])a[++idx][j-1]=a[i][j];n1=idx;}
            else for(int i=1;i<=n1;++i)a[i][j-1]=a[i][j];
        }
        int cnt=0,ans=(1<<30)-1;
        for(int i=1;i<=n1;++i)if(a[i][0]&1)cnt++,ans&=a[i][0];
        if(!cnt)for(int i=1;i<=m;++i)ans&=a[i][0];
        if(cnt&&cnt<m)ans--;
        std::cout<<ans;
    }
}
int main(){test::main();return 0;}