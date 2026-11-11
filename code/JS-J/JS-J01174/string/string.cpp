#include <bits/stdc++.h>
using namespace std;
string s,c;
long long n,x,sum;
int main(){
    cin>>n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(long long i = 1;i <= n;i++)
    {
        cin>>x;
        cin>>c;
        for(long long j = 1;j <= x;j++)
            s+=c;
    }
    long long l=s.length();
    for(long long i = 0;i < l/2;i++)
    {
        if(s[i]!=s[l-i-1])
            sum++;
    }
    cout<<sum;
    return 0;
}
