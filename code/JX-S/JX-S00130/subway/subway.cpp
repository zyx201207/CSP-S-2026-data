#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500050],a[505][505],t[505][505],x,y,k[500005];
long long xy[500050][25],yx[500050][25],wb[500050],u;
long long cnt[500050],len,ans=1e9;
bool ck(long long z){
    for(long long i=1ll;i<=len;i++){
	    if(cnt[i]==z) return true;
	}
	cout<<1<<endl;
	return false;
}	
void dfs(long long s,long long ww,long long vv){
	if(ck(ww)) return;
	vv+=t[xy[s][wb[s]]][yx[s][wb[s]]];
	for(long long i=1ll;i<=k[ww];i++){
		long long u=a[xy[s][wb[s]]][i];
		if(u==y){
			cout<<vv+w[x]+w[y]+t[ww][i]<<endl;
	        ans=min(ans,vv+w[x]+w[y]+t[ww][i]);
	        return;
	    } 
	    if(wb[u]>1ll){
	         for(long long j=1ll;j<=wb[u];j++){
				 if(ww!=xy[u][j]){
					 cnt[++len]=xy[u][j];
					 dfs(u,xy[u][j],vv+t[xy[u][j]][yx[u][j]]);
					 cnt[len]=0;
			     }
		     }	 
	    }
    }	
    return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1ll;i<=m;i++){
	    cin>>w[i];
	}
	for(long long i=1ll;i<=n;i++){
	    cin>>k[i];
	    for(long long j=1ll;j<=k[i];j++){
		    cin>>a[i][j]>>t[i][j];
		    u=a[i][j];
		    wb[u]+=1ll;
		    xy[u][wb[u]]=i;
		    yx[u][wb[u]]=j;
		}
	}
	for(long long i=1ll;i<=q;i++){
	    cin>>x>>y;
	    for(long long j=1ll;j<=wb[i];j++){
	       dfs(x,xy[x][j],0);
	    }
	    cout<<ans<<endl;
	    ans=1e9+10;
	}
    return 0;
}
