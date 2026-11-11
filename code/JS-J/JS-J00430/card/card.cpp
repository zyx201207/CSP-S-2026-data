#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[500005];
struct node
{
    char d;
    int id;
}a[500005];
bool cmp(node a,node b)
{
    return a.id<b.id;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].d;
        a[i].id=i;
    }
    for(int i=1;i<=n;i++)
    {
        sort(a+1,a+n+1,cmp);
        string s;
        s=a[i].d;
        for(int j=i+1;j<=n;j++)
        {
            s+=a[j].d;
            string ok;
            for(int k=0;k<s.size();k++)
            {
                ok+=s[k];
                if(s[k]==a[j].d)
                {
                    s=ok;
                    break;
                }
            }
        }
        for(int j=0;j<s.size();j++)
        {
            ans[s[j]-48]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",ans[i]);
    }


    return 0;
}
