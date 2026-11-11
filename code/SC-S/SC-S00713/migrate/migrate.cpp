#include<bits/stdc++.h>
using namespace std;
long long n,jl;
long long x[5005];
int d[5005];
int cnt[5005];
int b[5005];
vector<int>v[5005];
void dj(int st){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,st});
	cnt[st]=1;
	d[st]=0;
	while(q.size()){
		int p=q.top().second;
		long long w=q.top().first;
		q.pop();
		if(b[p]==1)continue;
		b[p]=1;
		for(auto i:v[p]){
			if(w+1<d[i]){
				d[i]=w+1;
				cnt[i]=cnt[p];
				q.push({w+1,i});
			}else if(w+1==d[i]){
				cnt[i]+=cnt[p];
			}
		} 
	}
}
void so(){
	cin>>n>>jl;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		v[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>jl)break;
			v[i].push_back(j);
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[j]=0;
			d[j]=2000005;
			b[j]=0;
		}
		dj(i);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		so();
	}
	return 0;
}