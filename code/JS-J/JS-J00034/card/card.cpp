#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
vector<int> b;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    b.resize(m+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        vector<int> s(1);
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=s.size();k++)
            {
                if(s[k]==a[j])
                {
                    for(int h=k;h<s.size();)
                    {
                        s.pop_back();
                    }
                }
            }
            s.push_back(a[j]);
        }
        for(int j=1;j<s.size();j++)
        {
            b[s[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
