#include <bits/stdc++.h>
using namespace std;
string s[1000001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
int n,a,c;
cin>>n>>a;
for(int i=1;i<=n;i++)
{

    for(int j=1;j<=a;j++)
    {

        cin>>c;
        s=s+c;
    }
}
int l=s.size();
for(int i=l-1;i>=i;i--)
{
    int p=1;
    if(p==i)
    {
        p=p+1;


    }
    else
    {

        i=p;
        cnt++;
    }
}

cout<<cnt;


    return 0;
}
