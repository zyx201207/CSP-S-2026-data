#include<bits/stdc++.h>
using namespace std;
struct node
{
    int cnt;
    char type;
}a[200005];
int n;
char c[200005];
string str;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].cnt);
        cin>>a[i].type;
        for(int j=1;j<=a[i].cnt;j++)
        {
            str+=a[i].type;
        }
    }
    long long ans=0;
    for(int i=0;i<str.size()/2;i++)
    {
        if(str[i]!=str[str.size()-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
