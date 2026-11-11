#include <bits/stdc++.h>
using namespace std;
string s[10000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,cnt=0,num=0;
    cin>>n;
    string c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s[cnt+j]=c;
        }
        cnt+=a;
    }
    for(int i=1;i<=cnt/2;i++)
    {
        if(s[i]!=s[cnt-i+1])
        {
            num++;
        }
    }
    cout<<num;
    return 0;
}
