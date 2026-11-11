#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[500005]={},b[500005]={};
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>v;
    bool arr[500005]={};
    for(int i=1;i<=n;i++)
    {
        memset(arr,0,sizeof(arr));
        for(int j=i;j<=n;j++)
        {
            if(arr[a[j]])
            {
                int idx=v.size()-1;
                while(v[idx]!=a[j])v.pop_back();
                continue;
            }
            v.push_back(a[j]);
            arr[a[j]]=1;
        }
        while(!v.empty())
        {
            b[v[v.size()-1]]++;
            v.pop_back();
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<" ";
    cout<<'\n';
    return 0;
}
