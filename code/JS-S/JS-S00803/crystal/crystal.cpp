#include<bits/stdc++.h>

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long m;
    std::cin>>n>>m;

    std::vector<long long> a(n+1);
    for(int i=1;i<=n;++i){
        std::cin>>a[i];
    }

    std::sort(a.begin()+1,a.end());
    a[0]=std::numeric_limits<long long>::min();
    std::vector<long long> sum(n+1,0);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }

    int ans=1;
    for(int i=2;i<=n;++i){
        int l=1,r=i;
        // std::cout<<"for "<<i<<":\n";
        while(l!=r){
            long long mid=(l+r)/2;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
            // std::cout<<l<<' '<<r<<'\n';
            // std::cin.ignore();
        }
        ans=std::max(ans,i-r+1);

    }
    std::cout<<ans;
    return 0;
}
