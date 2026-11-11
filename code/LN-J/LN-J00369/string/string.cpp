#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
#define ll long long
struct node
{
    ll num;
    char c;
}a[maxn];
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].c;
    }
    ll ans=0;
    for(int i=1,j=n;i<=j;)
    {
        if(a[i].num==a[j].num)
        {
            if(a[i].c!=a[j].c)
            {
                ans+=a[i].num;
            }
            i++;j--;
        }
        else
        {
            if(a[i].c!=a[j].c) ans+=min(a[i].num,a[j].num);
            if(a[i].num>a[j].num)
            {
                a[i].num-=a[j].num;
                j--;
            }
            else
            {
                a[j].num-=a[i].num;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
