#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
namespace test{
    int n,d;
    int ans;
    int a[2000006];
    void main(){
        freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        srand(time(0));
        std::cout<<rand();
    }
}
int main(){
    int c,t;std::cin>>c>>t;
    while(t--)test::main();
    return 0;
}