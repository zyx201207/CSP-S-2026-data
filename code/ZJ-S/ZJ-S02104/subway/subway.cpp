#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],x,y,ans;
set<int> st;
struct line
{
    int num;
    int t[20],sta[20],vis[20];
}l[505];
void jj(int now)
{
    st.clear();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<l[i].num;j++)
        {
            if(l[i].sta[j]==now)
                st.insert(i);
        }
    }
}
void dfs(int lin,int now,int tt)
{
	l[lin].vis[now]=1;
    if(l[lin].sta[now]==y)
    {
        ans=min(ans,tt);
        return;
    }
    for(int i=0;i<l[lin].num;i++)
    {
        jj(l[lin].sta[i]);
        if(l[lin].sta[now]==l[lin].sta[i])
            dfs(lin,i,tt);
        else if(st.size()>=2)
        {
            for(auto it:st)
            {
                if(it!=lin)
                {
                    int k=0;
                    for(int j=0;j<l[it].num;j++)
                        if(l[it].sta[j]==l[lin].sta[i])
                            k=j;
                    if(!l[it].vis[k])
                    	l[it].vis[k]=1,l[lin].vis[i]=1,dfs(it,l[lin].sta[i],tt+l[lin].t[i]+l[it].t[k]);
                }
            }
        }
    }
}
void solve()
{
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
    {
        cin>>l[i].num;
        for(int j=0;j<l[i].num;j++)
        {
            cin>>l[i].sta[j]>>l[i].t[j];
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        ans=10000000;
        jj(x);
        int k;
        for(auto it:st)
        {
            for(int j=0;j<l[it].num;j++)
            {
                if(l[it].sta[j])
                    k=j,l[it].vis[j]=1;
            }
            dfs(it,x,0);
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve();
    return 0;
}