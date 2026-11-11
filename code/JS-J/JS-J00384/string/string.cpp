#include<iostream>
#include<vector>
#include<fstream>
typedef long long ll;
std::vector<char> s;
int main()
{
    std::freopen("string.in","r",stdin);
    std::freopen("string.out","w",stdout);
    ll n,limit=0;
    std::cin>>n;
    s.push_back('0');
    for(ll i=1;i<=n;i++)
    {
        int a;
        char c;
        std::cin>>a>>c;
        limit+=a;
        for(int j=1;j<=a;j++)
            s.push_back(c);
    }
    int ans=0;
    for(int i=1;i<=limit/2;i++)
    {
        int left=i;
        int right=limit-i+1;
        if(s[left]!=s[right])
            ans++;
    }
    std::cout<<ans;
    return 0;
}
