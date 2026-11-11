#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,q,d,a[N],c,ans;
bool vis[N][N];
long long read(){
    char ch=getchar();long long a=0;
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
    return a;
}
void print(long long a)
{
    if(a<0){putchar('-');a=-a;}
    if(a>10)print(a/10);
    putchar(a%10+'0');
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),q=read();
    while(q--)
    {
        n=read(),d=read(),ans=0;
        for(int i=1;i<=n;i++)
            a[i]=read();
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                vis[i][j]=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if(a[j]-a[i]<=d)
                    vis[i][j]=1;
        for(int i=1;i<=n-3;i++)
        {
            for(int j=i+3;j<=n;j++)
            {
                int sum=0;
                for(int i1=i;i1<=j-1;i1++)
                {
                    for(int j1=i1+1;j1<=j;j1++)
                    {
                        sum+=vis[i1][j1];
                    }
                }
                if(sum==j-i+2)
                    ans++;
            }
        }
        print(ans),putchar('\n');
    }
    return 0;
}
