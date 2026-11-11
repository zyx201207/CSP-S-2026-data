#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
long long c,T,n,m,a[510005],b[510005],f[500005],ff[50005],d;
priority_queue<pair<long long,long long> >q;
vector<long long>v[100005];
long long dfs(long long nn){
	if(ff[nn]!=-1){
		return ff[nn];
	}
	
	long long t=0;
	for(long long i=0;i<v[nn].size();i++){
		if(f[v[nn][i]]+1==f[nn]){
			t=t+dfs(v[nn][i]);
		}
	}
	ff[nn]=t;
	return ff[nn];
}
void solve(){
	
	cin>>n>>d;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		v[i].clear();
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])<=d){
				v[j].push_back(i);
			}
		}
	}
	long long tt=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			f[j]=2100000000;
			ff[j]=0;
		}
		f[i]=0;
		ff[i]=1;
		for(long long j=i+1;j<=n;j++){
			for(long long g=0;g<v[j].size();g++){
				f[j]=min(f[j],f[v[j][g]]+1);
				if(f[j]==f[v[j][g]]+1){
					ff[j]=ff[v[j][g]]+ff[j];
				}
				if(ff[j]==2){
					tt++;
				}
			}
			
		}
		
	}cout<<tt<<"\n";
	/*long long tt=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			f[j]=2100000000;
		}
		f[i]=0;
		q.push({0,i});
		for(;q.size()!=0;){
			long long oo=q.top().second,uu=-q.top().first;
			q.pop();
			if(uu!=f[oo]){
				continue;
			}
			
			for(long long j=0;i<v[oo].size();j++){
				if(f[v[oo][j]]<uu+1){
					continue;
				}
				f[v[oo][j]]=uu+1;
				q.push({-f[v[oo][j]],v[oo][j]});
			}
			
		}
		
		for(long long j=1;j<=n;j++){
			ff[j]=-1;
		}
		ff[i]=0;
		for(long long i=1;i<=n;i++){
			if(dfs(i)==2){
				tt++;
			}
		}
	}
	cout<<tt<<"\n";*/
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(long long i=1;i<=T;i++){
		solve();
	}
} 
