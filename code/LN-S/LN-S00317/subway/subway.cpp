#include<bits/stdc++.h>
#define int long long
namespace test{
    int w[500005];
    std::vector<std::pair<int,int> >t[505];
    long long f[505][505];
    int a[505][505];
    std::vector<std::pair<int,int> >dy[500005];
    int c,n,m,d,q;
    void main(){
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;++i)std::cin>>w[i];
        for(int i=1;i<=n;++i){
            int k;std::cin>>k;
            for(int j=1;j<=k;++j){
                int q1,val;std::cin>>q1>>val;
                t[i].emplace_back(q1,val);
                dy[q1].emplace_back(i,val);
            }
        }
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)f[i][j]=1000000000000000000,a[i][j]=1000000000000000000;
        for(int i=1;i<=n;++i){
            for(auto pir:t[i]){
                int k=pir.first,k1=pir.second;
                for(auto pir1:dy[k])if(pir1.first!=i){
                    int l=pir1.first,k2=pir1.second;
                    a[i][l]=std::min(a[i][l],k1+k2);
                }
            }
        }
        //for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)std::cout<<a[i][j]<<' ';std::cout<<'\n';}
        for(int i=1;i<=n;++i)f[i][i]=0;
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)f[i][j]=a[i][j];
        for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)
            f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=n;++j)std::cout<<f[i][j]<<' ';
        //     std::cout<<'\n';
        // }
        while(q--){
            int s,t;
            std::cin>>s>>t;
            long long ans=w[s]+w[t];
            long long val=1000000000000000000;
            for(auto k1:dy[s])for(auto k2:dy[t]){
                long long m1=k1.first,m2=k2.first;
                long long n1=k1.second,n2=k2.second;
                val=std::min(val,f[m1][m2]+n1+n2);
            }
            ans+=val;
            std::cout<<ans<<'\n';
        }
    }
}
signed main(){test::main();return 0;}