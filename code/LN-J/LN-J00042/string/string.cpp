#include<bits/stdc++.h>
using namespace std;
int l[200001];
char id[200001];
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        l[i]=a;
        id[i]=c;
       //cout<<id[i]<<endl;
    }
    int u=1,v=n;
    long long ans=0;
    while(u<v)
    {
        if(id[u]!=id[v])
        {
            ans+=min(l[u],l[v]);
           //cout<<ans<<" "<<u<<v<<endl;
        }
        else if(l[u]==l[v])
        {
            u++;v--;
        }
        else if(l[u]>l[v])
        {
            l[u]-=l[v];
            v--;
        }
        else
        {
            l[v]-=l[u];
            u++;
        }
    }
    cout<<ans;
    return 0;
}
