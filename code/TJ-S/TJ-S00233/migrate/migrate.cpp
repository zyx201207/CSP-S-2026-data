#include <bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
int c,t,n,d,laste[5005],cnt,pos[5005],mncnt[5005],mn[5005],ind[5005],rind[5005],ans;
struct edge
{
    int v,nxt;
}e[5005*5005];
void adde(int u,int v)
{
    e[++cnt].v=v;
    e[cnt].nxt=laste[u];
    ind[v]++;
    rind[v]++;
    laste[u]=cnt;
    return;
}
queue<int> q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
    {
        cin>>n>>d;
        ans=0;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            ind[i]=rind[i]=laste[i]=0;
            mn[i]=inf;
        }
        for(int i=1;i<=n;i++) cin>>pos[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(pos[j]-pos[i]<=d) adde(i,j);
                else break;
            }
        }
        
        for(int s=1;s<=n;s++)
        {
			mn[s]=0; 
            q.push(s);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int i=laste[u];i;i=e[i].nxt)
                {
                    int v=e[i].v;
                    rind[v]--;
                    if(!rind[v]) q.push(v);
                    if(mn[v]<mn[u]+1) continue;
                    else if(mn[v]==mn[u]+1) mncnt[v]++;
                    else
                    {
                        mn[v]=mn[u]+1;
                        mncnt[v]=1;
                    }
                }
            }
            for(int i=s+1;i<=n;i++)
            {
                if(mncnt[i]==2) ans++;
                mncnt[i]=0;
                mn[i]=inf;
            }
            for(int i=laste[s];i;i=e[i].nxt)
            {
                int v=e[i].v;
                ind[v]--;
                //cout<<"ind"<<v<<' '<<ind[v]<<'\n';
            }
            for(int i=s+1;i<=n;i++) rind[i]=ind[i];
        }
        cout<<ans<<'\n';
    }
	return 0;
 }
 /*
 0 2
 4 2
 1 2 3 4
 5 2
 1 2 3 4 5
 */


