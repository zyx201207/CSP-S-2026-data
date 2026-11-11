#include<iostream>
#include<vector>
namespace test{
    int a[200005];
    int cnt[200005];
    int n,m;
    std::vector<int>d;
    void main(){
        freopen("card.in","r",stdin);
        freopen("card.out","w",stdout);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin>>n>>m;
        for(int i=1;i<=n;++i)std::cin>>a[i];
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                bool vis=0;
                for(int k:d)if(k==a[j]){vis=1;break;}
                if(vis)while(d.back()!=a[j])d.pop_back();
                d.push_back(a[j]);
            }
            for(int k:d)cnt[k]++;
            d.clear();
        }
        for(int i=1;i<=m;++i)std::cout<<cnt[i]<<' ';
    }
}
int main(){test::main();return 0;}