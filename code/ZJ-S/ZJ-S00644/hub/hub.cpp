#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,m,r[111000],dist[1100][1100];
int fa(int x){
	if(r[x]!=x) x=fa(r[x]);
	else return r[x];
}
long long miu=0,miv=0,an=1000000000;
void dfs(int h){
	if(h==k){
		if(miu==miv) return;
		if(dist[miu][miv]==1) return;
		long long ky=-1;
		for(int i=1; i<=n ;i++){
			long long ku=min(dist[i][miu],dist[i][miv]);
			ky=max(ku,ky);
		}
		an=min(an,ky);
		
	}
	else{
		for(int i=1; i<=n ;i++){
			if(miu==0){
				miu=i;
				dfs(h+1);
				miu=0;
			}
			else{
				miv=i;
				dfs(h+1);
				miv=0;
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		t--;
		cin>>n>>k;

		r[1]=1;
		memset(dist,0x3f,sizeof(dist));
		for(int i=1; i<=n-1; i++){
			r[i+1]=i+1;
			long long u,v;
			scanf("%lld%lld",&u,&v);
			dist[u][v]=1;
			dist[v][u]=1;
		}
		if(k==n){
			cout<<0<<endl;
			continue;
		}		
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int z=1; z<=n; z++){
					if(dist[z][i]+dist[z][j]<dist[i][j]){
						dist[i][j]=dist[z][i]+dist[z][j];
						dist[j][i]=dist[z][i]+dist[z][j];
					} 
				}
			}
		}
		for(int i=1; i<=n ;i++) dist[i][i]=0;
		if(k<=2){
			dfs(0);
			cout<<an<<endl;		
		}
		else{
			cout<<1<<endl;
		}
		
		
	}
	
	return 0;
} 
