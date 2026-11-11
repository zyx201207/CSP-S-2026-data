#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mk make_pair
#define pb push_back
using namespace std;
int read()
{
    char c=getchar(); int ret=0,f=1;
    while(c<48||c>57){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
    return ret*f;
}
#define N 500050
int c,n,m,d,q,w[N],k,a,V[N][22],T[N][22],_[N],x,y;
long long f[505][505],Ans;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    F(i,1,m)w[i]=read();
    F(i,1,n)
    F(j,1,n)f[i][j]=1e18;
    F(i,1,n)f[i][i]=0;

    F(i,1,n){
        k=read();
        F(j,1,k) {
            a=read();
            V[a][++_[a]]=i;
            T[a][_[a]]=read();
        }
    }

    F(i,1,m){
        F(j,1,_[i])
        F(k,j+1,_[i]){
            f[V[i][j]][V[i][k]]=min(f[V[i][j]][V[i][k]],(long long)T[i][j]+T[i][k]);
        }
    }
    F(i,1,n)
    F(j,1,n)f[i][j]=min(f[i][j],f[j][i]);

    F(k,1,n)
    F(i,1,n)
    F(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    
    F(i,1,q){
        x=read();y=read();
        Ans=1e18;
        F(i,1,_[x])
        F(j,1,_[y]){
            Ans=min(Ans,f[V[x][i]][V[y][j]]+T[x][i]+T[y][j]);
        }
        printf("%lld\n",Ans+w[x]+w[y]);
    }
}