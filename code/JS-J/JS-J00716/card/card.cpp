#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],sh[300001],cnt[300001];
bool f[300001],ff[300001];
vector<int>b;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        
    }
    
    for(int j=1;j<=n;j++)
    {
        b.clear();
        for(int k=1;k<=300001;k++)sh[k]=0;
        for(int k=1;k<=300001;k++)f[k]=0;
        for(int k=1;k<=300001;k++)ff[k]=0;
        for(int i=j;i<=n;i++)
        {
        
            b.push_back(a[i]);
            if(f[a[i]]==0){f[a[i]]=1;sh[a[i]]=i;}
            else
            {
                for(int o=1;o<=i-sh[a[i]];o++)b.pop_back();
                sh[a[i]]=i;

            }
            

        }
        //for(int k=1;k<=b.size();k++)cout<<b[k]<<" ";cout<<'\n';
        for(int k=1;k<=b.size();k++)ff[b[k]]=1;
        for(int k=1;k<=m;k++)cnt[k]+=ff[k];
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
    
    
    
}