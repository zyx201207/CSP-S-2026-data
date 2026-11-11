#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct EDGE
{
    int to,nxt;
}edge[N<<1];
int c,t,n,k,head[N],cnt=1;
int read()
{
    int sum=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
            sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
    return sum*f;
}
void init()
{
    memset(head,0,sizeof(head));
    cnt=0;
}
void add(int x,int y)
{
    edge[cnt]=EDGE{y,head[x]};
    head[x]=cnt++;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();t=read();
    while(t--)
    {
        n=read();k=read();
        init();
        for(int i=1;i<n;i++)
        {
            int x=read(),y=read();
            add(x,y);add(y,x);
        }
        int m=(n-1)/2;
        int ans=ceil((m+1-k)/4.0)+1;
        if(k==n) printf("0\n");
        else printf("%d\n",max(1,ans));
    }
    return 0;
}
