#include <bits/stdc++.h>
using namespace std;
pair<char,long long> p;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,x=0,y=-1;
    char c;
    long long s=0,ans=0;
    cin>>a;
    p.first=' ';
    vector<long long> v(a+2),ve(a+3);
    vector<pair<char,long long> > vec(1,p);
    v[0]=0;
    ve[a+1]=0;
    ve[a+2]=0;
    for(int i=1;i<=a;i++)
    {
        cin>>p.second>>p.first;
        s=s+p.second;
        vec.push_back(p);
    }
    for(int i=1;i<=a;i++)
        v[i]=vec[i].second+v[i-1];
    for(int i=a;i>=1;i--)
        ve[i]=vec[i].second+ve[i+1];
    while(v[x]+ve[a-y]<s)
    {
        if(v[x]>=ve[a-y])
        {
            y++;
            if(vec[x].first!=vec[a-y].first)
            {
                ans=ans-ve[a-y+1]+min(v[x],ve[a-y]);
            }
        }
        else
        {
            x++;
            if(vec[x].first!=vec[a-y].first)
            {
                ans=ans-v[x-1]+min(v[x],ve[a-y]);
            }
        }
    }
    cout<<ans;
    return 0;
}
