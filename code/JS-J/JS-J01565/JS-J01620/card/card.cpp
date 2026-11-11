#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
map<int,int> mp;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            mp[i]=1;
            for(int k=i+1;k<=n;k++)
                mp[k]=0;
        }
        for(int j=1;j<=n;j++)
            s[j]+=mp[j];
    }
    for(int i=1;i<=n;i++)
        cout<<s[i]<<' ';


    return 0;
}
