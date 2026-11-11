#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int dep[maxn],f[maxn],sum[maxn],stl[maxn][22],str[maxn][22];
int sta[maxn],n,lim,tot,num,fath[maxn];
int xyq[maxn],ver[maxn],root[maxn];
vector<int>edge[maxn];
mt19937_64 rng(time(0));
inline int find(int u){
	return root[u]==u?u:root[u]=find(root[u]);
}
inline int calc(int l,int r){
	return rng()%(r-l+1)+l;
}
inline void findp(int u,int dad){
	dep[u]=dep[dad]+1;
	fath[u]=dad;
	for(int v:edge[u]){
		if(v!=dad) findp(v,u);
	}
}
inline void ljd(int u,int dad,int now){
	xyq[u]=min(xyq[u],now);
	for(int v:edge[u]){
		if(v==dad) continue;
		ljd(v,u,now+1);
	}
}
inline void dfs(int u,int dad,int mid){
	// dfn[u]=++idx;
	for(int v:edge[u]){
		if(v!=dad) dfs(v,u,mid),f[u]=max(f[u],f[v]+1);
	}
	num+=(f[u]>=mid);
}
inline int solvel(int l,int r){
	int tmp=log2(r-l+1);
	return max(stl[l][tmp],stl[r-(1<<tmp)+1][tmp]);
}
inline int solver(int l,int r){
	int tmp=log2(r-l+1);
	return max(str[l][tmp],str[r-(1<<tmp)+1][tmp]);
}
inline int check(int mid){
	int s=1+mid,t=tot-mid;
	if(s>=t) return 1;
	// idx=0;
	for(int i=1;i<=tot;i++){
		int u=sta[i];
		// dfn[u]=++idx;
		num=0;
		for(int v:edge[u]){
			if(v==sta[i-1] or v==sta[i+1]) continue;
			dfs(v,u,mid);
			f[u]=max(f[u],f[v]+1);
		}
		// dfnr[u]=idx;
		// cout<<num+1<<" ";
		sum[i]=num+1+sum[i-1];
	}
	// cout<<"\n";
	if(sum[t]-sum[s-1]<=lim) return 1;
	int curs=0,curt=sum[t]-sum[s-1],j=s;
	// cout<<"s = "<<s<<" , t = "<<t<<"\n";
	for(int i=s;i<t;i++){
		curs+=sum[i]-sum[i-1];
		while(j<=t and curs+curt>lim) curt-=sum[j]-sum[j-1],j++;
		// cout<<"i = "<<i<<" , j = "<<j<<"\n";
		if(j>t) return 0;
		int m=((i+j)>>1);
		if(i+1<=m and solvel(i+1,m)-i>mid) continue;
		if(m+1<=j-1 and solver(m+1,j-1)+j>mid) continue;
		return 1;
	}
	return 0;
}
int main(){
	int T=0;
	while(true){
		T++;
		n=calc(17,22),lim=calc(2,n);
		for(int i=0;i<=n+1;i++) f[i]=0,edge[i].clear();
		for(int i=1;i<n;i++){
			int u=i+1,v=calc(1,i);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		findp(1,0);
		int vl=0;
		for(int i=1;i<=n;i++) if(dep[i]>=dep[vl]) vl=i;
		findp(vl,0);
		int vr=0;
		for(int i=1;i<=n;i++) if(dep[i]>=dep[vr]) vr=i;
		tot=0;
		while(vr){
			sta[++tot]=vr;
			vr=fath[vr];
		}
		sta[0]=sta[tot+1]=0;
		// idx=0;
		for(int i=1;i<=tot;i++){
			int u=sta[i];
			// cout<<u<<" ";
			// dfn[u]=++idx;
			for(int v:edge[u]){
				if(v==sta[i-1] or v==sta[i+1]) continue;
				dfs(v,u,n+1);
				f[u]=max(f[u],f[v]+1);
			}
			// dfnr[u]=idx;
			stl[i][0]=f[u]+i,str[i][0]=f[u]-i;
		}
		// cout<<"\n";
		int cur=log2(tot);
		for(int k=1;k<=cur;k++){
			for(int i=1;i+(1<<k)-1<=tot;i++){
				stl[i][k]=max(stl[i][k-1],stl[i+(1<<(k-1))][k-1]);
				str[i][k]=max(str[i][k-1],str[i+(1<<(k-1))][k-1]);
			}
		}
		int l=0,r=(tot/2),ans=(tot/2);
		while(l<=r){
			int mid=((l+r)>>1);
			// cout<<"mid = "<<mid<<"\n";
			if(check(mid)){
				// cout<<"result = true\n\n";
				ans=mid,r=mid-1;
			}
			else{
				// cout<<"result = false\n\n";
				l=mid+1;
			}
		}
		int res=n;
		for(int S=0;S<(1<<n);S++){
			if(__builtin_popcount(S)!=lim) continue;
			for(int i=1;i<=n;i++) root[i]=i;
			int m=0;
			for(int i=1;i<=n;i++){
				if(S&(1<<(i-1))) ver[++m]=i;
			}
			for(int i=1;i<=m;i++){
				for(int v:edge[ver[i]]){
					if(S&(1<<(v-1))) root[find(ver[i])]=find(v);
				}
			}
			int cnt=0;
			for(int i=1;i<=m;i++) if(root[ver[i]]==ver[i]) cnt++;
			if(cnt>2) continue;
			for(int i=1;i<=n;i++) xyq[i]=10000000;
			for(int i=1;i<=m;i++) ljd(ver[i],0,0);
			int mx=0;
			for(int i=1;i<=n;i++) mx=max(mx,xyq[i]);
			res=min(res,mx);
		}
		if(res!=ans){
			cout<<"Wrong answer on test # "<<T<<"\n";
			cout<<n<<" "<<lim<<"\n";
			for(int i=1;i<=n;i++){
				for(int j:edge[i]){
					if(i<j) cout<<i<<" "<<j<<"\n";
				}
			}
			cout<<"Expected "<<res<<" Found "<<ans<<"\n";
			for(int S=0;S<(1<<n);S++){
				if(__builtin_popcount(S)!=lim) continue;
				for(int i=1;i<=n;i++) root[i]=i;
				int m=0;
				for(int i=1;i<=n;i++){
					if(S&(1<<(i-1))) ver[++m]=i;
				}
				for(int i=1;i<=m;i++){
					for(int v:edge[ver[i]]){
						if(S&(1<<(v-1))) root[find(ver[i])]=find(v);
					}
				}
				int cnt=0;
				for(int i=1;i<=m;i++) if(root[ver[i]]==ver[i]) cnt++;
				if(cnt>2) continue;
				for(int i=1;i<=n;i++) xyq[i]=10000000;
				for(int i=1;i<=m;i++) ljd(ver[i],0,0);
				int mx=0;
				for(int i=1;i<=n;i++) mx=max(mx,xyq[i]);
				if(mx==res){
					for(int i=1;i<=n;i++){
						if(S&(1<<i-1)) cout<<i<<" ";
					}
					cout<<"\n";
				}
			}
			return 0;
		}
		if(T%20==0){
			cout<<"Accepted on test # "<<T<<"\n";
		}
		// cout<<ans<<"\n";
	}
	return 0;
}