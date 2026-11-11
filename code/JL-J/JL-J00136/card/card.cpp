#include <bits/stdc++.h>
using namespace std;
stack <int> s;
bool b[10010];
int a[10010],c[10010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(b[a[i]]==true)
            {
                while(s.top()==a[i])
                {

                    s.pop();
                }
                s.pop();
            }
            else
            {
                s.push(a[i]);
                b[a[i]]=true;
            }
        }
        while(s.empty())
        {
            c[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
}
