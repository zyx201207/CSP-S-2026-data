#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,d,x[2000005],res;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&t,&t);
    while(t--)
    {
        int way[2000005]={};
        res=0;
        vector<int> di;di.clear();
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                //cout<<x[j]-x[i]<<' ';
                if(x[j]-x[i]<=d)way[i]++;
                else break;
            }
            //cout<<way[i]<<' ';
        }
        di.push_back(1);
        for(int i=1;i<n;i++)
        {
            if(!way[i])
            {
                di.push_back(i);
            }
        }
        di.push_back(n);
        for(int i=0;i<di.size()-1;i++)
        {
            for(int j=di[i];j<di[i+1];j++)
            {
                if(way[j]>1)
                {
                    bool ad=0;
                    for(int x1=j+1;x1<j+way[j];x1++)
                    {
                        if(way[x1]==way[j])
                        {
                            ad=(ad^1);
                            //cout<<ad<<' ';
                        }
                        res=res+ad;
                    }
                }
            }
        }
        printf("%lld\n",res);
        //else cout<<0<<endl;
    }
    return 0;
}
