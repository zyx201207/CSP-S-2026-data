#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long>m1;
long long a[520000],d[320000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        m1.clear();
        for(int j=i;j<=n;j++)
        {
            long long l=n+1;
            for(int k=m1.size()-1;k>=0;k--)
            {
                if(m1[k]==a[j])
                {
                    l=k;
                    break;
                }
            }
            for(int k=l;k<m1.size();k++)
            {
                m1[k]=-1;
            }
            m1.push_back(a[j]);

       }
    for(int j=0;j<m1.size();j++)
        {
            //cout<<m1[j]<<' ';
            if(m1[j]!=-1)
            {
                d[m1[j]]++;
            }
        }
     //   cout<<endl;
    }

    for(int i=1;i<=m;i++)cout<<d[i]<<' ';
;    return 0;
}
