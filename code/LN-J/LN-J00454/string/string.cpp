#include <bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;++i){
        long long a;
        string c;
        cin>>a>>c;
        for(int j=1;j<=a;++j)s+=c;
    }
    long long x=s.size();
    for(long long i=0;i<x/2;++i){
        if(s[i]!=s[x-i-1])cnt+=1;
    }
    cout<<cnt;
    return 0;
}
