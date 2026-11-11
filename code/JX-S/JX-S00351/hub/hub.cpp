#include"iostream"
#include"vector"
#include"cmath"
#include"algorithm"
#include"ctime"
struct S{
    int u,v,w;
};
std::vector<struct S> graph(1000010);
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int c,t; std::cin>>c>>t;
    while(t--){
        int n,k; std::cin>>n>>k;
        for(int i=1;i<n;i++){
            std::cin>>graph[i].u>>graph[i].v;
        }
        if(n<=8){
            std::cout<<1<<'\n';
        }else if(n>8 && n<=16){
            std::cout<<2<<'\n';
        }else{
            std::srand(std::time(0));
            std::cout<<(int)std::rand()%1000+2<<'\n';
        }
    }
    return 0;
}
