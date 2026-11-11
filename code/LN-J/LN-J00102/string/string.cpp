#include<bits/stdc++.h>
using namespace std;
struct abc
{
    char ch;
    long long num;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>a[i].num>>a[i].ch;
    long long ans=0;
    for(int i = 1,j = n;i < j;)
    {
        if(a[i].ch!=a[j].ch)
        {
            long long x = min(a[i].num,a[j].num);
            ans+=x;
            a[i].num-=x;
            a[j].num-=x;
            if(a[i].num==0)i++;
            if(a[j].num==0)j--;
        }
        else
        {
            long long x = min(a[i].num,a[j].num);
            a[i].num-=x;
            a[j].num-=x;
            if(a[i].num==0)i++;
            if(a[j].num==0)j--;
        }
    }
    cout<<ans;
    return 0;
}
