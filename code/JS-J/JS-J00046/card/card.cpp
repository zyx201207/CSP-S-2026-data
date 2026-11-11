#include <bits/stdc++.h>

using namespace std;
int a[500005];
int b[500005];
int ant[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    stack <int> s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int k=0;
            bool q=false;
            while(!s.empty())
            {
                if(s.top()==a[j])
                {
                    s.pop();
                    q=true;
                    break;
                }
                else
                {
                    b[k]=s.top();
                    k++;
                    s.pop();
                }
            }
            if(q==false)
            {
                for(int w=k-1;w>=0;w--)
                {
                    s.push(b[w]);
                }
            }
            s.push(a[j]);
        }
        while(!s.empty())
        {
            int sum=s.top();
            ant[sum]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ant[i]<<" ";
    }
    return 0;
}
