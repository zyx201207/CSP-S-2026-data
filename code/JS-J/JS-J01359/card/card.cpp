#include<bits/stdc++.h>
using namespace std;
vector<int> hand,table;
int a[500005];
map<int,int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        hand.push_back(x);
    }
    for(int i=1;i<=m;i++) mp[i]=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j<n;j++)
        {
            if(mp[hand[j]]>=0)
            {
                for(int k=table.size()-1;k>=mp[hand[j]]+1;k--)
                {
                    mp[table[k]]=-1;
                    table.erase(table.begin()+k);
                }
            }
            else
            {
                table.push_back(hand[j]);
                mp[hand[j]]=table.size()-1;
            }
        }
        for(int j=0;j<table.size();j++) a[table[j]]++;
        for(int i=1;i<=m;i++) mp[i]=-1;
        table.clear();
    }
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
    return 0;
}
//dang ni re ai zhe ge shi jie shi,shi jie jiu hui yi tong wen ni
