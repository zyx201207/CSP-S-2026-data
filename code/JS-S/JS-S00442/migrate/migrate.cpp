#include<bits/stdc++.h>
using namespace std;
int c,t,n;
unsigned long long d,x[2000010];
map<string,int>deep;
map<int,string>peed;
long long ans=0;
vector<int>v[2000010];
void bfs()
{
    queue<int>q;
    for(int i=1;i<=n;i++)q.push(i),peed[i]=i+'0';
    while(q.size())
    {
        string de="0";
        int u=q.front();
        q.pop();
        for(int i:v[u])q.push(i),de[strlen(de)-1]=string(de[strlen(de)-1]+1),deep[string(peed[u]+de)]=i;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            long long in;
            cin>>in;
            x[i]=in+100000000;
        }
        for(int i=1;i<=n;i++)
        {
            int a=i;
            while(a<=n&&x[a+1]-x[i]<=d)
            {
                a++;
                v[i].push_back(a);
            }
        }
        bfs();
        for(string i:peed)
        {
            short vis[2000010];
            for(string s:peed)
            {
                int len=strien(i);
                if(len>=strlen(s))continue;
                bool cnt=0;
                for(int l=0;l<=len;l++)
                {
                    if(s[l]!=i[l])cnt=1;
                    break;
                }
                if(cnt)continue;
                vis[deep[s]]++;
            }
            for(int i=1;i<=2000000;i++)if(vis[i]==2)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
