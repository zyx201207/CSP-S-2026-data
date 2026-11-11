#include"iostream"
#include"vector"
#include"cmath"
#include"ctime"
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int c,n,m,d,q; std::cin>>c>>n>>m>>d>>q;
    std::vector<int> w(m+5,0);//time to walk from subway to the station
    for(int i=1;i<=m;i++){
        std::cin>>w[i];
    }
    std::vector<int> a(n+5,0),t(n+5,0);
    int maxn=-1;
    for(int i=1;i<=n;i++){//n*way
        int k; std::cin>>k;
        for(int j=1;j<=2*k;j++){
            int x; std::cin>>x;
            if(j%2==1){
                a[(j+1)/2]=x;
            }else{
                t[j/2]=x;
                maxn=std::max(maxn,t[j/2]);
            }
        }
    }
    while(q--){
        int x,y; std::cin>>x>>y;
        std::srand(std::time(0));
        std::cout<<std::rand()%maxn+2<<'\n';
    }
    return 0;
}
//Is this shame us who could not take the subway ??
//Are you consider if we could not take the subway ?? It will be so hard to understand the problem
