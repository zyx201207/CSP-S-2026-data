#include<bits/stdc++.h>
using namespace std;
string s;
long long sum=0;
int w(int c)
{
    long long q=s.length()-1;
    for(long long k=0;k<s.length()/2;k++)
    {
        if(s[q]-'a'!=s[k]-'a')
        {
            sum++;
        }
        q--;
    }
    return sum;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        for(int j=0;j<a;j++)
        {
            s+=b;
        }
    }
    cout<<w(n);
    return 0;
}
