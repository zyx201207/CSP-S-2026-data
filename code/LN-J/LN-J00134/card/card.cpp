#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int last[300005],used[500005],num[500005];
vector<pair<int,int> > controled;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(last[x]!=0)
            used[last[x]]=i-last[x];
        num[i]=i;
        last[x]=max(last[x],i);
    }
    for(int i=1;i<=n;i++)
    {
        vector<pair<int,int> > controled2;
        for(vector<pair<int,int> >::iterator j=controled.begin();j!=controled.end();j++)
        {
            if(j->first==0)
            {
                continue;
            }
            num[i]-=j->second;
            j->first--;
            if(j->first!=0)
                controled2.push_back(*j);
        }
        controled=controled2;
        if(num[i]!=0 && used[i]!=0)
        {
            controled.push_back({used[i]-1,num[i]});
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<num[last[i]]<<" ";
    }
    return 0;
}
