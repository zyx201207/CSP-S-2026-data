#include<bits/stdc++.h>
using namespace std;
int n,sum,cnt;
string s;
struct node
{
    int a;
    char c;
}st[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>st[i].a>>st[i].c;
        sum+=st[i].a;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=st[i].a;j++)
        {
            s+=st[i].c;
        }
    }
    for(int i=0;i<sum/2;i++)
    {
        if(s[i]!=s[sum-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
