#include <bits/stdc++.h>
using namespace std;
vector<long long>a;
long long max1;
long long maxx;
int n,m;
int h;
struct c
{
    long long sum;
    long long io;
};
vector<c>b;
void dfs(int e)
{
    if(h==1)
    {
        return;
    }
        for(int i=0;i<n;i++)
        {
            int g=0;
            for(int j=0;j<b.size();j++)
            {
                if(b[j].io==a[i])
                {
                    b[j].sum++;
                    g=1;
                    if(b[j].sum>maxx) maxx=b[j].sum;
                }
            }
            if(g==0) b.push_back({1,a[i]});
        }
        b.clear();
        if(e==0) return;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<max1)
        {
            k=1;
            a[i]++;
            dfs(e-1);
            a[i]--;
        }
    }
    if(k==0)
    {
        cout<<n<<" "<<1;
        h=1;
        return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r","stdin");
    freopen("crystal.out","w","stdout");

    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        int tyu;
        cin>>tyu;
        a.push_back(tyu);
        if(max1<tyu)
        {
            max1=tyu;
        }
    }
    dfs(m);
    if(h==0)
    {
    cout<<maxx;
    }
    return 0;
}
