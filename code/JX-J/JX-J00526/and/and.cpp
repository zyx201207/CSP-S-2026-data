#include<bits/stdc++.h>
using namespace std;
int n,m,t=0,a,p=0,x=0;
unordered_map<int,int>k;
vector<pair<int,int>>v;
bool cmp(pair<int,int>& a,pair<int,int>& b)
{
    if(a.second==b.second) return a.first>b.first;
    return a.second>b.second;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a);
        ++k[a];
    }
    for(auto i=k.begin();i!=k.end();++i)
    {
        v.push_back(*i);
    }
    sort(v.begin(),v.end(),cmp);
    t=v[0].first;
    p+=v[0].second;
    while(p<m)
    {
        ++x;
        t=t&v[x].first;
        p+=v[x].second;
    }
    printf("%d",t);
    return 0;
}
