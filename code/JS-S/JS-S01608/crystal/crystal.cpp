#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<climits>
using namespace std;

long long n,m,a[500005],pos,res,tot;
map<long long,long long> mp;
vector<long long> sum,cnt;
long long calc1(int pos)
{
    return sum.back()-sum[pos-1];
}
long long calc2(int pos)
{
    return cnt.back()-cnt[pos-1];
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    long long minn=LLONG_MAX;
    for(int i=1;i<=n;i++)   cin>>a[i],minn=min(minn,a[i]);
    if(minn<=0)
    {
        for(int i=1;i<=n;i++)   a[i]-=minn-1;
    }
    for(int i=1;i<=n;i++)   mp[a[i]]++;
    sort(a+1,a+n+1);
    unique(a+1,a+n+1);
    long long maxx=0;
    sum.push_back(0),cnt.push_back(0);
    int pos=1;
    for(auto &p:mp)
    {
        int v=p.first,k=p.second;
        while(pos<sum.size() && calc1(pos)<v*calc2(pos)-m)   pos++;
        long long res=k+calc2(pos);
        if(pos>1)   res+=(m-v*calc2(pos)+calc1(pos))/(v-a[pos-1]);
        maxx=max(maxx,res);
        sum.push_back(sum.back()+v*k),cnt.push_back(cnt.back()+k);
    }
    cout<<maxx<<'\n';
    return 0;
}
