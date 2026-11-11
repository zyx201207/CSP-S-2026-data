#include<bits/stdc++.h>
using namespace std;
long long c,t1,n,d0,x[2000002],now,f[2000001],t[2000001],d[2000001],sz[2000001],hd1[2000001],hd[2000001],z[2000001],ans;
vector<long long> a[2000001];
void getds(long long x){
	d[x]=d[f[x]]+1;
	sz[x]=1;
	for(long long i=0;i<a[x].size();i++){
		getds(a[x][i]);
		sz[x]+=sz[a[x][i]];
	}
}
void gethdz(long long x){
	for(long long i=0;i<a[x].size();i++)
		gethdz(a[x][i]);
	if(!a[x].size()) hd1[x]=1;
	else hd1[x]=hd1[a[x][0]]+a[x].size()-1;
	long long u=0;
	if(a[x].size()){
		hd[x]=hd[a[x][0]];
		if(a[x].size()>1){
			u=a[a[x][1]].size();
			if(sz[a[x][0]]==1) hd[x]+=hd1[a[x][1]];
			else hd[x]+=u;
		}
	}
	z[x]=hd[x]-u+t[x];
}
void solve(long long l,long long r){
	for(long long i=l;i<=r;i++)
		a[i].clear();
	f[r]=r;
	for(long long i=r-1;i>=l;i--){
		f[i]=upper_bound(x+l,x+r+1,x[i]+d0)-x-1;
		a[f[i]].push_back(i);
	}
	for(long long i=l;i<=r;i++){
		long long u=lower_bound(x+l,x+r+1,x[i]-d0)-x;
		if(i>=u+2) t[i]=lower_bound(x+l,x+r+1,x[u+2]-d0)-lower_bound(x+l,x+r+1,x[u+1]-d0);
		else t[i]=0;
	}
	if(c==11||c==12){
		for(long long i=l;i<=r;i++)
			ans+=t[i];
		return;
	}
	d[r]=0;
	getds(r);
	gethdz(r);
	for(long long i=l;i<=r;i++)
		ans+=z[i];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t1;
	for(long long o=0;o<t1;o++){
		ans=0;
		cin>>n>>d0;
		for(long long i=1;i<=n;i++)
			cin>>x[i];
		x[n+1]=4e18;
		now=1;
		for(long long i=1;i<=n;i++)
			if(x[i+1]-x[i]>d0){
				solve(now,i);
				now=i+1;
			}
		cout<<ans<<endl;
	}
	return 0;
}
