#include<bits/stdc++.h>
using namespace std;
int n,a[500001],m,s[300001];
vector<int> v;
vector<int> c;
int b[300001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        v.clear();
        memset(b,0,sizeof(b));
        c.clear();
        for (int j=i;j<=n;j++)
        {
            if (b[a[j]]!=0)
            {
                int len=v.size();
                int cnt=0;
                for (int k=b[j];k<=len;k++)
                {
                    v.erase(v.begin()+k);
                    b[c[++cnt]]=0;
                }
                c.clear();
            }
            else{
                v.push_back(a[j]);
                b[a[j]]=v.size();
                c.push_back(a[j]);
            }
        }
        s[v.size()]++;
    }
    for (int i=1;i<=m;i++)
    {
        cout<<s[i]<<" ";
    }
    return 0;
}
