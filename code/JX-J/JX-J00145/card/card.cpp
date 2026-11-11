#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool f[300000];
int sum[300000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500000];
    stack<int>d;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        memset(f,0,sizeof(m));
        for(int j=i;j<n;j++)
        {
            if(!f[a[j]])
            {
                d.push(a[j]);
                f[a[j]]=1;
            }
            else
            {
                while(d.top()!=a[j])
                {
                    f[d.top()]=0;
                    d.pop();
                }
                d.pop();
                f[a[j]]=0;
            }
        }
        for(int j=0;j<m;j++)
        {
            sum[i]+=f[i];
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<sum[i]<<" ";
    }
}
