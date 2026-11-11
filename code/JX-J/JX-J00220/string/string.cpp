#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int num;
    char c;
}a[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].num>>a[i].c;
    }
    int p=n;
    long long sum=0,ans=0;
    for(int i=1;i<=n;++i)
    {

        while(p>0&&a[i].num>=a[p].num&&a[i].num>0)
        {
            if(a[p].c!=a[i].c)
            {
                ans+=a[p].num;
            }
            a[i].num-=a[p].num;
            a[p].num=0;
            --p;
        }
        if(p<=0)break;
        if(a[p].c!=a[i].c)
        {
            ans+=a[i].num;
        }
        a[p].num-=a[i].num;
        a[i].num=0;
    }
    cout<<ans;
    return 0;
}
