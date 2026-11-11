#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long x,sum=0;
    char a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>a;
        for(int j=1;j<=x;j++)
        {
            s+=a;
        }
    }
    int l=0,r=s.length()-1;
    for(int i=1;i<=(s.length()+1)/2;i++)
    {
        if(s[l]!=s[r])
        {
            sum++;
        }
        l++;
        r--;
    }
    cout<<sum;
}
