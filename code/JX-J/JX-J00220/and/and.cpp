#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
void fs(int ind,vector<int>v)
{
    if(ind<0)return;
    int p=(1<<ind);
    vector<int>a;
    for(int i=0;i<v.size();++i)
    {
        if((v[i]&p)!=0)
        {
            a.push_back(v[i]);
        }
    }
    if(a.size()>=m)
    {
        ans+=p;
        fs(ind-1,a);
    }
    else
    {
        fs(ind-1,v);
    }
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int>a;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    fs(30,a);
    cout<<ans;
    return 0;
}
