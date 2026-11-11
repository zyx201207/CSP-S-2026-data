#include<bits/stdc++.h>
using namespace std;
struct node
{
    int ans,wei;
}q[200003];
int t[200003],n,m,a[200003],zui[2000];
long long num[200003][100],o;
void aa(int a,int id)
{
    if(a==0) return ;
    aa(a/2,id);
    if(a%2==0) t[id]++;
    if(a%2==1)
    {
        t[id]++;
        num[id][t[id]]=1;
    }
}
bool cmp(node x,node y)
{
    if(x.ans!=y.ans) return x.ans>y.ans;
    return x.wei<y.wei;
}
void wei(int x,int y)
{
    for(int i=1;i<=max(t[x],t[y]);i++)
    {
        if(num[x][i]==num[y][i] && num[x][i]==1) num[y][i]=1;
        else num[y][i]=0;
    }
}
int main()
{
    freopen("and,in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //aa(a[i],i);
    }
    int maxn=0;
    for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
    cout<<maxn;
    /*
    for(int i=1;i<=n;i++)
        for(int j=1;j<=t[i];j++)
        {
            if(num[i][j]==1) q[i].ans++;
            q[i].wei=i;
        }
    sort(q+1,q+n+1,cmp);
    for(int i=1;i<m;i++)
    {
        wei(q[i].wei,q[i+1].wei);
    }
    for(int i=1;i<t[m];i++)
    {
        if(num[m-1][i]==1)
        {
            o+=i;
            cout<<i<<endl;
        }

    }
    cout<<o;
    */
    return 0;
}
