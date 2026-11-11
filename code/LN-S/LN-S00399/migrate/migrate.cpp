#include <bits/stdc++.h>
using namespace std;
long long n;
long long d;
vector<long long> a;
vector<long long>sumi;
int m;
int yui;
struct c
{
    long long idx;
    long long su;
};

int dfs(long long sum,int am)
{
int nt=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+2;j<n;j++)
        {
            sum=0;
            am=INT_MAX;
            if(a[j]-a[i]<=d)
            {
                continue;
            }
            vector<c>ab;
            ab.push_back({0,a[i]});
            long long p=0;
            long long  pa;
            for(int k=1;k<=d;k++)
            {
                for(long long l=p;l<ab.size();l++)
                {
                    ab.push_back({ab[l].idx+1,ab[l].su+k});
                    if(ab[l].su+k==a[j]&&ab[l].idx<am)
                    {
                        sum=1;
                        am=ab[l].idx;
                        ab.pop_back();
                    }
                    if(ab[l].su+k==a[j]&&ab[l].idx==am)
                    {
                        sum++;
                        ab.pop_back();
                    }
                     if(ab[l].su+k>a[j])
                    {
                        ab.pop_back();
                    }
                    pa=l;
                }
            }
            p=pa;
            if(sum==2)
            {
                nt++;
            }
        }
    }
    return nt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
freopen("migrate.in","r","stdin");
freopen("migrate.out","w","stdout");
    long long sum;int am=INT_MAX;
    cin>>yui;
    cin>>m;
    while(m--)
    {
        cin>>n>>d;
            for(int i=0;i<n;i++)
            {
            long long tyu;
            cin>>tyu;
            a.push_back(tyu);
            if(a[i]-a[i-1]>d)
            {
                a.pop_back();
            }
            }
        if(d==1)
        {
            cout<<0;
        }
    sumi.push_back(dfs(sum,am));
sum=0;
am=INT_MAX;

    }
for(int i=0;i<sumi.size();i++)
{
    cout<<sumi[i]<<endl;
}
    return 0;
}
