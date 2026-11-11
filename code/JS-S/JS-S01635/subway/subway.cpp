#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k,ans=0;
vector<pair<int,int> >a[500005];
int w[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        int minx=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            cin>>x>>y;
            a[x].push_back({i,y});
            if(a[x].size()==2) minx=min(minx,a[x][1].second+a[x][2].second);
        }
        if(n==2){
            ans=0;
            for(int i=1;i<=q;i++)
            {
                cin>>x>>y;
                ans+=w[x]+w[y];
                if(a[x].size()==1&&a[y].size()==1&&a[x][1].first==a[y][1].first)
                {
                    ans+=a[x][1].second+a[y][1].second;
                }
                else
                {
                    if(a[x].size()==1&&a[y].size()==2)
                    {
                        if(a[x][1].first==1) 
                        {
                            ans+=min(a[x][1].second+a[y][1].second,a[x][1].second+a[y][2].second+minx);
                        }
                        else 
                        {
                            ans+=min(a[x][1].second+a[y][2].second,a[x][1].second+a[y][1].second+minx);
                        }
                    }
                    else if(a[x].size()==2&&a[y].size()==1)
                    {
                        if(a[y][1].first==1) 
                        {
                            ans+=min(a[y][1].second+a[x][1].second,a[y][1].second+a[x][2].second+minx);
                        }
                        else 
                        {
                            ans+=min(a[y][1].second+a[x][2].second,a[y][1].second+a[x][1].second+minx);
                        }
                    }
                    else{
                        ans+=min(a[y][1].second+a[x][1].second,min(a[y][2].second+a[x][2].second,min(a[y][1].second+a[x][2].second+minx,a[y][2].second+a[x][1].second+minx)));
                    }
                }
                cout<<ans;
            }
        }
    }
    return 0;
}