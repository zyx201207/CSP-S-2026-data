#include <bits/stdc++.h>
using namespace std;
int n,x;
char c;
vector<char> v;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i = 1;i<=n;i++)
    {
        cin>>x>>c;
        for(long long j = 1;j<=x;j++)
        {
            v.push_back(c);
        }
    }
    int change = 0;
    for(long long i = 0;i<=v.size()-1;i++)
    {
        if(v[i]!=v[v.size()-1-i])
        {
            //cout<<v[i]<<" "<<v[v.size()-1-i]<<endl;
            change++;
        }
    }
    cout<<change/2;
    return 0;
}
