#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
    int num;
    char ch;
}a[200010];
int p,q,m,flag,ans;
char k;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].ch;
    }
    p=0,q=n;
    k='A',m=0,flag=0;
    while(p<q)
    {
        if(flag==0)
        {
            if(k==a[q].ch||k=='A')
            {
                if(m>=a[q].num)
                {
                    flag=0;
                    k=a[q].ch;
                    m=m-a[q].num;
                    q--;
                    continue;
                }
                else
                {
                    flag=1;
                    k=a[q].ch;
                    m=a[q].num-m;
                    p++;
                    continue;
                }
            }
            else
            {
                if(m>=a[q].num)
                {
                    flag=0;
                    m=m-a[q].num;
                    ans+=a[q].num;
                    q--;
                    continue;
                }
                else
                {
                    flag=1;
                    ans+=m;
                    k=a[q].ch;
                    m=a[q].num-m;
                    p++;
                    continue;
                }
            }
        }
        else
        {
            if(k==a[p].ch||k=='A')
            {
                if(m>a[p].num)
                {
                    flag=1;
                    m=m-a[p].num;
                    k=a[p].ch;
                    p++;
                    continue;
                }
                else
                {
                    flag=0;
                    m=a[p].num-m;
                    k=a[p].ch;
                    q--;
                    continue;
                }
            }
            else
            {
                if(m>a[p].num)
                {
                    flag=1;
                    m=m-a[p].num;
                    ans+=a[p].num;
                    p++;
                    continue;
                }
                else
                {
                    flag=0;
                    ans+=m;
                    k=a[p].ch;
                    m=a[p].num-m;
                    q--;
                    continue;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
