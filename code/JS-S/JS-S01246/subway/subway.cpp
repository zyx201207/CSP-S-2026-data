#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,t1;
int w[505][50005],t[505][50005],r[500005],nu[50005],line[505][50005],line1[505];
int reg[505][50005];
bool flag[505];
int cle()
{
    for(int i=1;i<=504;i++)
    {
        flag[i]=false;
    }
    return 0;
}
int dfs(int st,int en,int ti,int li,int loc)
{
    //cout<<loc<<' '<<ti<<endl;
    if(loc==en)
    {
        //cout<<1<<endl;
        //cout<<ti<<endl;
        t1=min(t1,ti);
        return INT_MAX;
    }
    for(int i=1;i<=line1[loc];i++)
    {
        for(int j=1;j<=nu[line[loc][i]];j++)
        {
            if(flag[w[line[loc][i]][j]]==false)
            {
                flag[w[line[loc][i]][j]]=true;
                //cout<<t[line[loc][i]][w[line[loc][i]][j]]<<" "<<t[line[loc][i]][loc]<<endl;
                dfs(st,en,ti+t[line[loc][i]][reg[w[line[loc][i]][j]][line[loc][i]]]+t[line[loc][i]][reg[loc][line[loc][i]]],line[loc][i],w[line[loc][i]][j]);
                flag[w[line[loc][i]][j]]=false;
            }
        }
    }
    return INT_MAX;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>r[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        nu[i]=k;
        for(int j=1;j<=k;j++)
        {
            int s1,s2;
            cin>>w[i][j]>>t[i][j];
            reg[w[i][j]][i]=j;
            line1[w[i][j]]+=1;
            line[w[i][j]][line1[w[i][j]]]=j;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s1,s2;
        t1=INT_MAX;
        cin>>s1>>s2;
        cle();
        flag[s1]=true;
        t1=min(t1,dfs(s1,s2,0,line[s1][i],s1));
        cout<<(t1+r[s1]+r[s2])<<endl;
    }
    return 0;
}