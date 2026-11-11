#include<bits/stdc++.h>
using namespace std;
int sum;
vector<long long> a;
vector<long long>c;
struct d;
{
    int a1;
    int a2;

}d[50000005];
void dfs(int i)
{
    for(int j=i;j<m;j++)
    {
        c.push_back(a[j])
        for(int k=i;k<j;k++)
        {
            if(a[k]==a[j])
            {
                for(int h=k;h<j;k++)
                {
                    c.pop_back()；
                }
            }
        }
    }

}
int main()
{
   freopen("card.in","r","std.in");
   freopen("card.out","w","std.out");
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int tyu;
        cin>>tyu;
        a.push_back(tyu);
    }
    for(int i=0;i<n;i++)
    {
        dfs(i);
    }
    for(int i=0;i<n;i++)
    {
        for(int i=1;i<=m;i++)
        {
            if(c[i]==b[i].a1)
            {
                b[i].a2++;
            }
            else if(b[i].a1==0){
                b[i].a1=c[i];
                b[i].a2++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<d[i].a2<<" ";
    }
return 0;
}
