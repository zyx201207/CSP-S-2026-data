#include<bits/stdc++.h>
using namespace std;
long long k=0;
long long u=1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int b;
    cin>>b;
    long long a;
    char c;
    string s;
    for(int i=1;i<=b;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s[u]+=c;
            u++;
        }
    }
    cout<<"0";
}
