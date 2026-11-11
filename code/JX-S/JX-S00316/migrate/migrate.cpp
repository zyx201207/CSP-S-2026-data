#include<bits/stdc++.h>
using namespace std;
struct road
{
    long long start;
    long long end;
    bool flag;
};
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        long long n,d;
        cin>>n>>d;
        vector<long long> a;
        a.resize(1000000);
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        vector<road> road_been;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=i+1;j<=n;j++)
            {
                if(abs(a[j]-a[i])<=d)
                {
                    road_been.push_back({i,j,1});
                }
                else
                {
                    road_been.push_back({i,j,0});
                }
            }
        }
        vector<road> road_new;
        vector<road> r;
        int l=0;
        for(long long i=0;i<road_been.size();i++)
        {
            if(road_been[i].flag==true)
            {
                road_new.push_back({road_been[i].start,road_been[i].end,1});
                l++;
            }
        }
        int k=0;
        for(long long i=0;i<l-1;i++)
        {
            if(road_new[i].start==road_new[i+1].start)
            {
                r.push_back({road_new[i+1].start,road_new[i+1].end,road_new[i+1].flag});
                k++;
            }
        }
        cout<<r.size()-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
