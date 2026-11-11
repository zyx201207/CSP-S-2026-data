#include<bits/stdc++.h>
using namespace std;

int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int maxn=-1;

    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }

    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,a[i]&a[j]);
                //cout<<a[i]<<"&"<<a[j]<<"="<<maxn<<endl;
            }
        }
        cout<<maxn;
    }
    else if(m==n)
    {
        int c=a[1];
        for(int i=2;i<=n;i++)
        {
            c&=a[i];
        }
        cout<<c;
    }

    else return 0;


    return 0;
}
