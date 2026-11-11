#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5010;
int c,t,n,d,x[N],nxt[N],ans,f[N][N],g[N][N],h[N][N];

inline void read(int&x){
	x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f^=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x=(f?-x:x);
}

void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}


signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(t);
	while(t--){
		ans=0;
		read(n),read(d);
		int p=1;
		for(int i=1;i<=n;++i){
			read(x[i]);
			while(x[i]-x[p]>d)nxt[p++]=i-1;
		}
		while(p<=n)nxt[p++]=n;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i>=j)f[i][j]=0,g[i][j]=h[i][j]=INT_MAX;
				else f[i][j]=g[i][j]=h[i][j]=INT_MAX;
		while(p<=n)nxt[p++]=n;
		for(int i=n;i>=1;--i)
			for(int j=n;j>=i;--j){
				if(i>=j)continue;
				if(nxt[i]>j){
					f[i][j]=1;
					if(h[i][j]>i+1)g[i][j]=2;
					if(h[i][j]>i+2)h[i][j]=2;
					continue;
				}
				if(nxt[i]>i)f[i][j]=f[nxt[i]][j]+1;
				if(nxt[i]>i)g[i][j]=g[nxt[i]][j]+1;
				if(nxt[i]>i+1)g[i][j]=min(g[i][j],f[nxt[i]-1][j]+1);
				if(nxt[i]>i)h[i][j]=h[nxt[i]][j]+1;
				if(nxt[i]>i+1)h[i][j]=min(h[i][j],g[nxt[i]-1][j]+1);
				if(nxt[i]>i+2)h[i][j]=min(h[i][j],f[nxt[i]-2][j]+1);
			}
		//	for(int i=1;i<=n;++i)
		//		for(int j=i+1;j<=n;++j)
		//			cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<g[i][j]<<" "<<h[i][j]<<endl;
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				if(g[i][j]<INT_MAX&&f[i][j]==g[i][j]&&(f[i][j]<h[i][j]||h[i][j]>=INT_MAX))++ans;
		cout<<ans<<endl;
	}
	return 0;
}

/*
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2000010;
int c,t,n,d,x[N],g[N][2],nxt[N],ans,fn[N],f[N][2][3];

inline void read(int&x){
	x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f^=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x=(f?-x:x);
}

void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}

signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	read(c),read(t);
	while(t--){
		ans=0;
		read(n),read(d);
		int p=1;
		for(int i=1;i<=n;++i){
			read(x[i]);
			while(x[i]-x[p]>d)nxt[p++]=i-1;
			g[i][0]=g[i][1]=0;
			f[i][0][0]=f[i][1][0]=f[i][1][1]=f[i][1][2]=0;
		}
		while(p<=n)nxt[p++]=n;
		int l=1;
		for(int i=1;i<=n;++i)
			if(nxt[i]==i){
				for(int j=l;j<=i;++j)
					fn[j]=i;
				l=i+1;
			}
		for(int i=n;i>=1;--i){
			/*
			if(nxt[i]==i){
				g[i][1]=g[i][0]=-1;
//				cout<<g[i][0]<<" "<<g[i][1]<<endl;
				continue;
			}
			if(i==1)g[i][1]=-1;
			else if(nxt[i]==i+1){
				if(x[i]-x[i-1]>d)g[i][1]=g[i+1][0];
				else if(x[i+1]-x[i-1]<=d)g[i][1]=i+1;
				else g[i][1]=g[i+1][1];
			}
			else{
				if(x[nxt[i]]-x[i-1]<=d)g[i][1]=nxt[i];
				else g[i][1]=g[nxt[i]][1];
			}
			if(nxt[i]==i+1)g[i][0]=g[i+1][0];
			else g[i][0]=g[nxt[i]][1];
//			cout<<g[i][0]<<" "<<g[i][1]<<endl;
			if(nxt[i]==i){
				g[i][1]=g[i][0]=0;
//				cout<<g[i][0]<<" "<<g[i][1]<<endl;
				continue;
			}
			if(i==1)g[i][1]=0;
			else if(nxt[i]==i+1){
				if(x[i]-x[i-1]>d)g[i][1]=1+g[i+1][0];
				else if(x[i+1]-x[i-1]<=d)g[i][1]=1;
				else g[i][1]=1+g[i+1][1];
			}
			else{
				if(x[nxt[i]]-x[i-1]<=d)g[i][1]=1;
				else g[i][1]=1+g[nxt[i]][1];
			}
			if(nxt[i]==i+1)g[i][0]=g[i+1][0];
			else g[i][0]=g[nxt[i]][1];
//			cout<<g[i][0]<<" "<<g[i][1]<<endl;
		}
		for(int i=n;i>=1;--i){
			for(int j=0;j<2;++j)
				for(int k=0;k<3;++k){
					if(j==0&&k)continue;
					if(j!=0&&i-j<1)continue;
					if(k!=0&&i-k<1)continue;
					/*
					if(nxt[i]==i){
						f[i][j][k]={-1,-1};
						continue;
					}
					vector<int>v,z;
					v.push_back(i);
					if(j!=0)v.push_back(i-j);
					if(k!=0)v.push_back(i-k);
					for(int u:v){
						z.push_back(nxt[u]);
						if(nxt[u]>u+1)z.push_back(nxt[u]-1);
						if(nxt[u]>u+2)z.push_back(nxt[u]-2);
					}
					sort(z.begin(),z.end(),greater<int>());
					int siz=z.size();
					if(siz>1&&z[0]==z[1]){
						if(siz>2&&z[1]==z[2])f[i][j][k]={-1,-1};
						else if(siz==2)f[i][j][k]={z[0],g[z[0]][0]};
						else f[i][j][k]={z[0],g[z[0]][1]};
					}
					else{
						int a1=z[0],a2=0,a3=0;
						if(siz>1)a2=z[0]-z[1];
						if(siz>2)a3=z[0]-z[2];
						f[i][j][k]=f[a1][a2][a3];
						cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k].first<<" "<<f[i][j][k].second<<endl;
						cout<<a1<<" "<<a2<<" "<<a3<<endl;
					}
					f[i][j][k]=0;
					if(nxt[i]==i){
						f[i][j][k]=0;
						continue;
					}
					vector<int>v,z;
					v.push_back(i);
					if(j!=0)v.push_back(i-j);
					if(k!=0)v.push_back(i-k);
					for(int u:v){
						z.push_back(nxt[u]);
						if(nxt[u]>u+1)z.push_back(nxt[u]-1);
						if(nxt[u]>u+2)z.push_back(nxt[u]-2);
					}
					sort(z.begin(),z.end(),greater<int>());
					int siz=z.size();
					int z2=0;
					int K=i-k;
					if(k!=0)z2=nxt[K];
					if(siz>1&&z[0]==z[1]){
						if(siz>2&&z[1]==z[2])f[i][j][k]=0;
						else if(siz==2)f[i][j][k]=z[0]-i-1+g[z[0]][0];
						else f[i][j][k]=z[0]-i-1+g[z[0]][1];
					}
					else{
						int a1=z[0],a2=0,a3=0;
						if(siz>1)a2=z[0]-z[1];
						if(siz>2)a3=z[0]-z[2];
						f[i][j][k]=f[a1][a2][a3];
						if(j==0&&k==0)continue;
						if(siz==2)f[i][j][k]+=z[1]-i;
						else if(siz>3)f[i][j][k]+=z[1]-max(i,z2);
			//			f[i][j][k]=f[a1][a2][a3]+(siz>2?z[1]-max(i+1,z[2]):0);
						cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
						cout<<a1<<" "<<a2<<" "<<a3<<endl;
					}
				}
		}
		for(int i=1;i<=n;++i){
			/*
			pair<int,int>T=f[i][0][0];
			if(T.first==-1)continue;
			else if(T.second==-1)ans+=fn[i]-T.first+1;
			else ans+=T.second-T.first;
			ans+=f[i][0][0];
			cout<<"*"<<ans<<" "<<i<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
*/