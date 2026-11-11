#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
bool c[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(!c[a[j]])
            {
                b[a[j]]++;
                c[a[j]]=true;
            }
            else
            {
                for(int k=j-1;k>=1;k--)
                {
                    if(a[k]==a[j])
                    {
                        break;
                    }
                    else
                    {
                        b[a[k]]--;
                        c[a[k]]=false;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i]!=0)
            {
                cout<<b[i]-1<<" ";
            }
        }
        cout<<endl;
        for(int j=1;j<=n;j++)
        {
            c[j]=false;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=0)
        {
            cout<<b[i]-1<<" ";
        }
    }
    return 0;
}
