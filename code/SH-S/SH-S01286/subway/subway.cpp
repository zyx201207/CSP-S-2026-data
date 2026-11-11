#include<bits/stdc++.h>
using namespace std;
long long w[500005],u[500005][25],p[500005][25],f[505][505],res[505][505];
bool flag[505];
struct node{
	long long n,p;
	bool operator >(const node &z) const{return p>z.p;}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<node,vector<node>,greater<node> > qq;
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)	cin>>w[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			u[a][++u[a][0]]=i;
			p[a][u[a][0]]=t;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)	res[i][j]=f[i][j]=-1;
		res[i][i]=f[i][i]=0;
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=u[i][0];j++){
			for(long long k=j+1;k<=u[i][0];k++){
				if(f[u[i][j]][u[i][k]]==-1)	f[u[i][j]][u[i][k]]=p[i][j]+p[i][k];
				else	f[u[i][j]][u[i][k]]=min(f[u[i][j]][u[i][k]],p[i][j]+p[i][k]);
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)	flag[j]=0;
		flag[i]=1;
		qq.push({i,0});
		while(!qq.empty()){
			node no=qq.top();
			qq.pop();
			if(no.p>res[i][no.n])	continue;
			flag[no.n]=1;
			for(long long j=1;j<=n;j++){
				if(flag[j])	continue;
				if(f[no.n][j]<0)	continue;
				if(f[no.n][j]+res[i][no.n]<res[i][j] or res[i][j]<0){
					res[i][j]=f[no.n][j]+res[i][no.n];
					qq.push({j,res[i][j]});
				} 
			}
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y,xx,yy;
		cin>>xx>>yy;
		x=min(xx,yy);
		y=max(xx,yy);
		long long ans=res[u[x][1]][u[y][1]]+p[x][1]+p[y][1];
		for(long long j=1;j<=u[x][0];j++){
			for(long long k=1;k<=u[y][0];k++)	ans=min(ans,res[u[x][j]][u[y][k]]+p[x][j]+p[y][k]);
		}
		ans=ans+w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}

