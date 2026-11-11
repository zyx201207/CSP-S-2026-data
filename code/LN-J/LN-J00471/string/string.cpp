#include<iostream>
#include<string.h>
namespace test{
    long long ans,l;
    std::string s=" ";
    void main(){
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int n;std::cin>>n;
        for(int i=1;i<=n;++i){
            int a;char c;
            std::cin>>a>>c;
            for(int j=1;j<=a;++j)s+=c,l++;
        }
        int mid=(l+1)/2;
        if(l&1){
            for(int i=1;i<mid;++i)if(s[mid-i]!=s[mid+i])++ans;
            std::cout<<ans;
        }
        else{
            for(int i=0;i<mid;++i)if(s[mid-i!=s[mid+1+i]])++ans;
            std::cout<<ans;
        }
    }
}
int main(){test::main();return 0;}