#include<bits/stdc++.h>
const double PI = 3.14159;
using namespace std;
long long  n,m;
long long  cards[500005],times[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long  i=1;i<=n;i++)
    {
        cin>>cards[i];
    }
    for(long long  i=1;i<=n;i++)
    {
        long long  table[500005];
        long long  top=0;
        for(long long  j=i;j<=n;j++)
        {
            for(long long  k=1;k<=top;k++)
            {
                if(table[k]==cards[j])
                {
                    for(long long  t=k;t<=top;t++) table[t]=0;
                    top = k-1;
                }
            }
            top++;
            table[top]=cards[j];
        }
        for(long long  j=1;j<=top;j++) times[table[j]]++;
    }
    for(long long  i=1;i<=m;i++) cout<<times[i]<<' ';
    return 0;
}
