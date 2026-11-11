#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1000005];
long long mp[1000005];
long long app[100005],mark[1000005];
set <long long> st;
vector<long long> v;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }


    for(long long i=1;i<=n;i++)
    {
        long long l=0;
        for(int kl=1;kl<=m;kl++)
        {

            app[kl]=0;
        }
        for(long long k=i;k<=n;k++)
        {

            if(app[a[k]]==0)
            {
                l++;
                mp[l]=a[k];
                app[a[k]]=1;
                continue;
            }
            else if(app[a[k]]==1)
            {
                long long fl=INT_MAX;
                for(int o=1;o<=l;o++)
                {

                    if(mp[o]==a[k] )
                    {
                        app[mp[o]]=0;
                        mp[o]=-1;
                        fl=o;

                    }
                    if(o>fl)
                    {
                        app[mp[o]]=0;
                        mp[o]=-1;

                    }
                }
                l++;
                mp[l]=a[k];
                app[a[k]]=1;
            }

        }
        for(long long o=1;o<=m;o++)
            {

                if(app[o]==1)
                {
                    mark[o]++;
                }
            }

    }
    for(int i=1;i<=m;i++)
    {

        cout<<mark[i]<<' ';
    }
    return 0;
}
