#include<bits/stdc++.h>
using namespace std;
vector<long long>v[1000005];
long long ans=0,k,a[1000005],d[1000005];
bool vis[1000005],vis2[1000005];
void dfs1(long long x){
	vis[x]=1;
	for(long long i=0;i<v[x].size();i++){
		long long nx=v[x].at(i);
		if((!vis[nx])&&(a[nx]==1)){
			dfs1(nx);
		}
	}
}
void dfs2(long long x,long long dis){
	d[x]=min(d[x],dis);
	vis2[x]=1;
	for(long long i=0;i<v[x].size();i++){
		long long nx=v[x].at(i);
		if(!vis2[nx]){
			if((dis==0)&&(a[nx]==1)){
				dfs2(nx,0);
			}
			else{
				dfs2(nx,dis+1);
			}
		}
	}
}
void DFS(long long x,long long n){
	if(x>n){
		for(long long i=1;i<=n;i++){
			d[i]=1e18;
			vis[i]=0;
			vis2[i]=0;
		}
		long long cn=0;
		for(long long i=1;i<=n;i++){
			if(a[i]==1) cn++;
			//cout<<a[i]<<" ";
		}
		//cout<<"\n";
		if(cn!=k) return;
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			if((a[i]==1)&&(!vis[i])){
				dfs1(i);
				cnt++;	
			}
		}
		if(cnt>2) return;
		//cout<<"yy\n";
		for(long long i=1;i<=n;i++){
			if((!vis2[i])){
				dfs2(i,0);
				break;
			}
		}
		for(long long i=1;i<=n;i++) if(d[i]) vis2[i]=0;
		for(long long i=1;i<=n;i++){
			if((!vis2[i])){
				dfs2(i,0);
				break;
			}
		}
		long long mx=0;
		for(long long i=1;i<=n;i++){
			//cout<<d[i]<<" ";
			mx=max(mx,d[i]);
		}
		//cout<<"\n";
		ans=min(ans,mx);
		return;
	}
	a[x]=1;
	DFS(x+1,n);
	a[x]=0;
	DFS(x+1,n);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long testid,t;
	cin>>testid>>t;
	while(t--){
		ans=0;
		long long n;
		cin>>n>>k;
		for(long long i=1;i<n;i++){
			long long x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=1e18;
		DFS(1,n);
		cout<<ans<<"\n";
	}
	return 0;
}
