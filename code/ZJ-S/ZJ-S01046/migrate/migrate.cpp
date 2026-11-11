#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
inline ll read(){
    int c,w=1;
    ll ret=0;
    while((c=getchar())>'9'||c<'0') w=(c=='-'?-1:1);
    ret=c-48;
    while((c=getchar())<='9'&&c>='0') ret=ret*10+c-48;
    return w*ret;
}

int const maxn=2e6+5,inf=1e9+5,maxv=5005;

int c,t,n;
ll d;

int g[5005][5005],dis[5005][5005];
ll f[5005][5005];

ll x[maxn];

void sol(){
    n=read(),d=read();
    for(int i=1;i<=n;i++) x[i]=read();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        	f[i][j]=0;
            if(i!=j) g[i][j]=inf;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        	if(i==j) continue;
            if(x[i]-x[j]<=d){
                g[i][j]=1;
                f[i][j]=1;
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(g[u][v]>g[u][k]+g[k][v]){
                    g[u][v]=g[u][k]+g[k][v];
                    f[u][v]=f[u][k]*f[k][v];
                }else if(g[u][v]==g[u][k]+g[k][v]){
                    f[u][v]+=f[u][k]*f[k][v];
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=(f[i][j]==2);
//            if(f[i][j]==2){
//            	/mxlen=max(mxlen,g[i][j]);
//			}
        }
    }
    
    cout<<ans<<'\n';
	

}


void sol2(){
	
    n=read(),d=read();
    for(int i=1;i<=n;i++) x[i]=read();
	
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        	f[i][j]=0;
            if(i!=j) g[i][j]=inf;
            dis[i][j]=inf;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        	if(i==j) continue;
            if(x[i]-x[j]<=d){
                g[i][j]=1;
                f[i][j]=1;
            }
        }
    }
	int ans=0;
	queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
        dis[i][i]=0;
        f[i][i]=1;
        while(!q.empty()){
        	int u=q.front();
        	q.pop();
        	for(int j=1;j<=n;j++){
        		if(g[u][j]==1){
        			if(dis[i][j]>dis[i][u]+1){
        				dis[i][j]=dis[i][u]+1;
        				f[i][j]=f[i][u];
        				q.push(j);
					}else if(dis[i][j]==dis[i][u]+1){
						f[i][j]+=f[i][u];
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
		//	cout<<dis[i][j]<<' ';
            ans+=(f[i][j]==2);
        }
      //  puts("");
    }

    cout<<ans<<'\n';

	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
    	if(n<=500) sol();
    	else if(n<=5000){
   			sol2();
		}
	}


    return 0;
}