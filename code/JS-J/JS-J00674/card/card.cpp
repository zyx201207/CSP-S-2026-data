#include<bits/stdc++.h>
using namespace std;
int n,m,d[300001],e[300001],c[500001];
stack<int> a,b;
int main()
{
    freopen("card.in","w",stdin);
    freopen("card.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a.push(x);
        c[i]=x;
    }

    for(int p=1;p<=n;p++)
    {
        for(int q=1;q<=m;q++)
            e[q]=0;
        for(int i=1;i<=n;i++)
        {
            int x=a.top();
            b.push(x);
            a.pop();
            if(e[x])
            {
                b.pop();
                while(x!=b.top())
                    b.pop();
                b.pop();
                b.push(x);
            }
            if(a.empty())
            {
                while(!b.empty())
                {
                    d[b.top()]++;
                    b.pop();
                }
                for(int h=1;h<=n;h++)
                {
                    a.push(c[h]);
                }
                for(int g=1;g<=n-i;g++)
                {
                    a.pop();
                }
            }
            e[x]=1;

        }
    }
    for(int i=1;i<=m;i++)
        cout<<d[i]<<" ";
    return 0;
}
