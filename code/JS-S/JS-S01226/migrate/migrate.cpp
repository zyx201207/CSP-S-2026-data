#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5005;
int c,T,n;
long long d,x[N];
int nxt[M][20],cnt[M][M];
int dist(int u,int v)
{
    int ans=0;
    for(int len=0; len<20; len++)
        if( nxt[u][len]<v )
            ans+=(1<<len),u=nxt[u][len];
    for(int len=19; len>=0; len--)
        if( nxt[u][len]<v )
            ans+=(1<<len),u=nxt[u][len];
    if( u==v ) return ans;
    else       return ans+1;
}
void solve1()
{
    for(int i=1; i<=n; i++)
    {
        nxt[i][0]=max(i,nxt[i-1][0]);
        while( nxt[i][0]<n && x[nxt[i][0]+1]<=x[i]+d )
            nxt[i][0]++;
    }
    for(int i=1; i<20; i++)
        for(int j=1; j<=n; j++)
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
    long long ans=0;
    for(int i=n; i>=1; i--)
    {
        for(int j=n; j>=i; j--)
        {
            int nx=nxt[i][0];
            if( j<=nx )
            {
                cnt[i][j]=1;
                continue;
            }
            cnt[i][j]=cnt[nx][j];
            if( nx-1>=i && dist(nx-1,j)==dist(nx,j) )
                cnt[i][j]+=cnt[nx-1][j];
            if( nx-2>=i && dist(nx-2,j)==dist(nx,j) )
                cnt[i][j]+=cnt[nx-2][j];
            cnt[i][j]=min(3,cnt[i][j]);
            if( cnt[i][j]==2 ) ans++;
        }
    }
    memset(cnt,0,sizeof cnt);
    printf("%lld\n",ans);
}
void solve2()
{
    long long dd=x[2]-x[1];
    long long num=d/dd;
    long long ans=max(0ll,n-2*num+1);
    if( num<=1 ) ans=0;
    printf("%lld\n",ans);
}
void solve3()
{
    int mid;
    for(int i=1; i<=n; i++)
        if( x[i]-x[1]<=d && x[n]-x[i]<=d )
        {
            mid=i;
            break;
        }
    if( mid==1 || mid==n )
    {
        printf("0\n");
        return ;
    }
    int x11=0,x12=0,x21=0,x22=0;
    for(int i=1; i<mid; i++)
    {
        if( x[mid+1]-x[i]<=d && ( mid==n-1 || x[mid+2]-x[i]>d ) ) x11++;
        if( x[mid+1]-x[i]>d ) x12++;
    }
    for(int i=mid+1; i<=n; i++)
    {
        if( x[i]-x[mid-1]<=d && ( mid==2 || x[i]-x[mid-2]>d ) ) x21++;
        if( x[i]-x[mid-1]>d ) x22++;
    }
 //   cout<<x11<<' '<<x12<<' '<<x21<<' '<<x22<<endl;
    long long ans=1ll*x11*x22+1ll*x12*x21;
    printf("%lld\n",ans);
}
int main()
{
    freopen("migrate2.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while( T-- )
    {
        scanf("%d%lld",&n,&d);
        for(int i=1; i<=n; i++)
            scanf("%lld",&x[i]);
      //  if( c<=10 ) solve1();
       // else if( c<=12 ) solve2();
      //  else if( c<=14 )
      solve3();
    }
}
