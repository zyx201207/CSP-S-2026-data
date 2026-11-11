#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e6+10;
int c,t;
int n,k,f[N],s[N],D,dep[N],fl,u[N],v[N];
vector<int>g[N];
void dfs1(int x,int fa){
//	cout<<x<<" "<<fa<<endl;
	dep[x]=0;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs1(y,x);
		dep[x]=max(dep[x],dep[y]+1);
	}
	int num=0,p=0;
	for(int y:g[x]){
		if(y==fa||dep[y]+1<=D)continue;
		if(f[y])num++,p=y;
	}
	if(num>1){
		s[x]=f[x]=0;
		for(int y:g[x]){
			if(y==fa||dep[y]+1<=D)continue;
			f[x]+=f[y]+s[y];
		}
		f[x]++;
	}
	else{
		if(!num)s[x]=0,f[x]=1;
		else{
			int ma=0;
			for(int y:g[x]){
				if(y!=fa&&y!=p)ma=max(ma,dep[y]+1);
			}
			if(ma+s[p]+1>D){
				if(ma>=D){
					s[x]=0,f[x]=1+f[p]+s[p];
				}
				else{
					s[x]=D-ma;
					f[x]=f[p]+s[p]+1-s[x];
				}
			}
			else s[x]=s[p]+1,f[x]=f[p];
		}
	}
}
void dfs2(int x,int fa){
	if(fl)return;
	dep[x]=0;
	int d2=0;
	for(int y:g[x]){
		if(dep[y]+1>dep[x])d2=dep[x],dep[x]=dep[y]+1;
		else if(dep[y]+1>d2)d2=dep[y]+1;
	}
	int num=0,p=0,p2=0,zz=0;
	for(int y:g[x]){
		if(dep[y]+1<=D)continue;
		if(f[y]){
			num++;
			if(!p)p=y;
			else p2=y;
		}
	}
	if(num>1){
		s[x]=f[x]=0;
		for(int y:g[x]){
			if(dep[y]+1<=D)continue;
			f[x]+=f[y]+s[y];
		}
		f[x]++;
	}
	else{
		if(!num)s[x]=0,f[x]=1;
		else{
			int ma=0;
			for(int y:g[x]){
				if(y!=p){
					if(dep[y]+1>ma)zz=y,ma=dep[y]+1;
				}
			}
			if(ma+s[p]+1>D){
				if(ma>=D){
					s[x]=0,f[x]=1+f[p]+s[p];
				}
				else{
					s[x]=D-ma;
					f[x]=f[p]+s[p]+1-s[x];
				}
			}
			else s[x]=s[p]+1,f[x]=f[p];
		}
	}
	int lf=f[x],ls=s[x],lde=dep[x];
//	cout<<f[x]<<"\n";
	for(int z:g[x]){
		if(z==fa)continue;
		if(dep[z]+1==dep[x])dep[x]=d2;
		int lfz=f[z],lsz=s[z],ldz=dep[z];
		if(num>2){
			if(dep[z]+1>D)f[x]-=f[z]+s[z];
		}
		else if(z==zz||z==p||z==p2){
			int num=0,p=0;
			for(int y:g[x]){
				if(y==z||dep[y]+1<=D)continue;
				if(f[y])num++,p=y;
			}
			if(num>1){
				s[x]=f[x]=0;
				for(int y:g[x]){
					if(y==z||dep[y]+1<=D)continue;
					f[x]+=f[y]+s[y];
				}
				f[x]++;
			}
			else{
				if(!num)s[x]=0,f[x]=1;
				else{
					int ma=0;
					for(int y:g[x]){
						if(y!=z&&y!=p)ma=max(ma,dep[y]+1);
					}
					if(ma+s[p]+1>D){
						if(ma>=D){
							s[x]=0,f[x]=1+f[p]+s[p];
						}
						else{
							s[x]=D-ma;
							f[x]=f[p]+s[p]+1-s[x];
						}
					}
					else s[x]=s[p]+1,f[x]=f[p];
				}
			}
		}
		dep[z]=max(dep[z],dep[x]+1);
		if(f[x]+f[z]<=k){
//			cout<<f[x]<<" "<<f[z]<<" "<<s[x]<<" "<<s[z]<<"\n";
			fl=1;
			return;
		}
		dfs2(z,x);
		f[x]=lf,s[x]=ls,dep[x]=lde;
		f[z]=lfz,s[z]=lsz,dep[z]=ldz;
	}
}
bool check(int d){
	D=d,fl=0;
	dfs1(1,0);
	if(f[1]<=k)return 0;
//	for(int i=1;i<n;i++){
//		dfs1(u[i],v[i]),dfs1(v[i],u[i]);
//		if(f[u[i]]+f[v[i]]<=k)return 0;
//	}
//	return 1;
	dfs2(1,0);
	return fl^1;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
//	cout<<check(1)<<endl;
	int now=-1;
	for(int i=(1<<20);i;i>>=1){
		if(now+i<=n&&check(now+i))now+=i;
	}
	cout<<now+1<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
