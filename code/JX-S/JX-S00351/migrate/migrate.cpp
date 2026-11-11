#include"iostream"
#include"vector"
#define ll long long
std::vector<ll> v(2000010,0);
ll n,d;
void mig(){
    std::vector<ll> dis(n+5,0);
    bool special=(v[3]-v[2]==v[2]-v[1]);
    for(int i=4;i<=n;i++){
        dis[i]=v[i]-v[i-1];
        special=(bool)(special && (v[i]-v[i-1]));
    }
    if(special){
        std::cout<<n-3<<'\n';
    }

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll c,t; std::cin>>c>>t;//The mark of ceshidian
    while(t--){
        std::cin>>n>>d;
        v.clear();
        for(int i=1;i<=n;i++){
            std::cin>>v[i];
        }
        mig();
    }
    return 0;
}
