#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[500010];
set<int>s;
vector<int>v;
map<int,int>d;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>f[i];
    for(int i=0;i<n;i++)
    {
        s.clear();
        v.clear();
        int t;
        for(int j=i;j<n;j++)
        {
            t=s.size();
            s.insert(f[j]);
            v.push_back(f[j]);
            if(t==s.size()){
                s.clear();
                t=0;
                int k;
                for(k=i;k<j;k++)
                {
                    if(f[k]==f[j]){
                        break;
                    }
                    s.insert(f[k]);
                    t++;
                }
                for(int b=k;b<n;b++)v[b]=-1;
                t++;
                s.insert(f[j]);
            }
            t++;
        }
        for(auto x:s)d[x]++;
    }
    for(int i=1;i<=m;i++)cout<<d[i]<<' ';
    return 0;
}
