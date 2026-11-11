#include<bits/stdc++.h>
using namespace std;
int l[310][310];
long long a[310];
long long c;
struct N{
	int x;
	int y;
	friend bool operator < (N p,N q){
		return p.y>q.y;
	}
};
int n;
long long d;
void bfs(int x){
	priority_queue<N>q;
	q.push({x,0});
	while(!q.empty()){
		N tp=q.top();
		q.pop();
		if(l[x][tp.x]!=-1) continue;
		l[x][tp.x]=tp.y;
		for(int i=tp.x+1;i<=n;i++){
			if(a[i]-a[tp.x]<=d&&l[x][i]==-1){
				q.push({i,l[x][tp.x]+1});
			}
		}
	}
	return ;
}
int ss,tt,f=0;
void dfs(int o,int yy){
	if(yy==l[ss][tt]-1){
		if(a[tt]-a[o]<=d){
			f++;
		}
		return ;
	}
	for(int i=o+1;i<tt;i++){
		if(a[i]-a[o]<=d){
			dfs(i,yy+1);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int u,t;
	cin>>u>>t;
	while(t--){
		c=0;
		cin>>n>>d;
		if(n<=9){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) l[i][j]=-1;
			}
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
				bfs(i);
				for(int j=i+3;j<=n;j++){
					ss=i;
					tt=j;
					f=0;
					dfs(i,0);
					if(f==2) c++;
				//	cout<<i<<" "<<j<<" "<<l[i][j]<<' ';
				}
			}
			cout<<c<<"\n";
		}
		else{
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					vector<int>cc;
					int s=i,f=0;
					while(1){
						if(s>=j){
							cc.push_back(j);
							break;
						}
						cc.push_back(s);
						int h=upper_bound(a+1,a+n+1,s+d)-a-1;
						if(h>s) s=h;
						else{
							f=1;
							break;
						}
					}
					if(f==0){
						int ff=0;
						for(int ii=0;ii+2<cc.size();ii++){
							if(a[cc[ii+1]-1]+d>=a[cc[ii+2]]&&a[cc[ii]]+d>=a[cc[ii+1]-1]){
								if(cc[ii+1]-2<=cc[ii]) ff++;
								else{
									if(a[cc[ii+1]-2]+d<a[cc[ii+2]]||a[cc[ii]]+d<a[cc[ii+1]-2]){
										ff++;
									}
								}
							}
						}
						if(ff==1) c++;
					}
				}
			}
			cout<<c<<"\n";
		}
	}
	return 0;
} 
