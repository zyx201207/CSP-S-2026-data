#include<iostream>
#include<string.h>
namespace test{
    void main(){
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int a,c;
        std::string b,d;
        std::cin>>a>>b>>c>>d;
        if(a==c){
            std::cout<<1;
            if(b[1]==d[1]&&b[0]==d[0]){
                std::cout<<1;
                if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
                    std::cout<<1;
                    if(std::abs(static_cast<int>(b[2]-d[2]))==1)std::cout<<1;
                    else std::cout<<0;
                }
                else std::cout<<"00";
            }
            else std::cout<<"000";
        }
        else std::cout<<"0000";
    }
}
int main(){test::main();return 0;}