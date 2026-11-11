#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=500010;
int n,m;
int a[N];
int ft[N];
int fh[N];
int sz;
int ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        sz=0;
        for(int k=1;k<=N;k++)
        {
            ft[k]=0;
            fh[k]=0;
        }
        for(int j=i;j<=n;j++)
        {
            int pai=a[j];
            if(ft[pai]==0)
            {
                ft[pai]=++sz;
                fh[sz]=pai;
            }
            else
            {
                int temp=sz;
                for(int k=ft[pai]+1;k<=temp;k++)
                {
                    ft[fh[k]]=0;
                    fh[k]=0;
                    sz-=1;
                }
            }
        }
        for(int k=1;;k++)
        {
            if(fh[k]==0)
                break;
            ans[fh[k]]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
