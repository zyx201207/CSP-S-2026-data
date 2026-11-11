#include<bits/stdc++.h>
using namespace std;
int arr[200005],mk[200005];
vector<int>vec[200005];
queue<int>q;
long long ans;
void bfs(int s,int n)
{
    memset(mk,0,sizeof mk);
    while(q.size()) q.pop();
    q.push(s);
    while(q.size())
    {
        int h=q.front();
        q.pop();
        for(auto k:vec[h])
        {
            ++mk[k];
            q.push(k);
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(mk[i]==3) ++ans;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;++i)
    {
        int n,d;
        scanf("%d%d",&n,&d);
        for(int j=1;j<=n;++j) scanf("%d",&arr[j]);
        long long j=1;
        for(int s=1;s<=d;++s) j*=s;
        printf("%lld\n",n-(d+(arr[2]-arr[1])));
        ans=0;
    }
    return 0;
}
