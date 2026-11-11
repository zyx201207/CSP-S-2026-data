#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
const int M=3*1e5+5;
int n,m,a[N],b[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        vector<int>v;
        int mp[M]={};
        for(int j=i;j<=n;j++)
        {
            int k=a[j];
            if(mp[k])
            {
                v.resize(mp[k]-1);
                v.push_back(k);
            }
            else
            {
                mp[k]=j;
                v.push_back(k);
            }
        }
        for(int j=0;j<v.size();j++)
            b[v[j]]++;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
