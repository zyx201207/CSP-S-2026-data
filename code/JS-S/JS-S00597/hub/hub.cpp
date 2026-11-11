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

#define N 1000500
vector<int>G[N];
int c,T,n,k,u,v,l,r,mi,Ans;
int h[N],vi[N],g[N],ss,q[N],_[N],qn;
void dfs(int p)
{
    if(!h[p])return;
    if(vi[p])return;
    vi[p]=1;
    for(auto u:G[p]){
        dfs(u);
    }
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(); T=read();
    while(T--){
        n=read(); k=read();
        F(i,2,n){
            u=read();v=read();
            G[u].pb(v);
            G[v].pb(u);
        }

        if(c==13 || c==14){
            if(k>=n){
                printf("0\n");
            }else{
                if(k>=n/2)printf("1\n");
                else{
                    printf("%d\n",(n/2-k+3)/4+1);
                }

            }
        }
        else{

            F(i,1,n)h[i]=0;
            F(i,n-k+1,n)h[i]=1;
            Ans=n;
            do{
                ss=0;
                F(i,1,n)vi[i]=0;
                F(i,1,n)if(h[i]&&!vi[i]){
                    dfs(i);
                    ++ss;
                }
                if(ss>2)continue;
                F(i,1,n)g[i]=n;
                F(i,1,n)if(h[i]){
                    g[i]=0; q[qn=1]=i; _[i]=1;
                    F(q1,1,qn){
                        int  v= q[q1]; _[v]=0;
                        for(auto u:G[v]){
                            if(g[u]>g[v]+1){
                                g[u]=g[v]+1;
                                if(!_[u])
                                q[++qn]=u,_[u]=1;
                            }
                        }
                    }
                }
                //F(i,1,n)cerr<<g[i]<<' ';
                int _Ans=0;
                F(i,1,n)_Ans=max(_Ans,g[i]);
                Ans=min(Ans,_Ans);
            }while(next_permutation(h+1,h+n+1));
            printf("%d\n",Ans);
        }

        F(i,1,n){
            vector<int>().swap(G[i]);
        }
        
    }
}