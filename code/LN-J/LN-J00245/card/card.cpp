#include <bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    queue<int>g;
    long long n,m;
    cin>>n>>m;
    int a[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        g.push(a[i]);
    }
    for(long long i=1;i<=n;i++)
    {
        long long cnt=0;
        queue<int> c=g;
        for(long long k=0;k<i;k++)
        {
            c.pop();
        }
        int p[n];
        for(long long z=0;z<n;z++)
        {

            p[z]=c.front();
            c.pop();
            for (long long i=0 ;i<z;i++)
            {
                if (p[z]==p[i])
                {
                    for(int w=0;w<n;w++)
                    {
                        p[w]=0;
                    }
                }
            }

        }
        for(long long v=1;v<=m;v++)
        {
            for(long long o=0;o<v;o++)
            {
                if(p[o]==i)
                {
                    cnt++;
                }
            }

        }
  cout<<cnt<<" ";
    }

    return 0;
}
