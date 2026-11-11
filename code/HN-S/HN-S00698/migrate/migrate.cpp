#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[1000000],dijj[1000000],ans[1000000],sum;
void dij(long long u,long long v){
	priority_queue<pair<long long,long long>>pq;
	for(long long i=u+1;i<=v;i++){
		dijj[i]=LONG_LONG_MAX;
	}
	dijj[u]=0;
	pq.push({0,u});
	while(pq.size()){
		pair<long long,long long>fr=pq.top();
		pq.pop();
		fr.first*=-1;
		//cout<<fr.second<<' '<<fr.first<<'\n';
		if(fr.second==v){
			return;
		}
		if(fr.first>dijj[fr.second]){
			continue;
		}
		for(long long i=fr.second+1;i<=v;i++){
			if(i==fr.second+1||a[i]-a[fr.second]<=d){
				if(fr.first+1<dijj[i]){
					ans[i]=0,dijj[i]=fr.first+1,pq.push({(fr.first+1)*-1,i});
				}
				else if(fr.first+1==dijj[i]){
					ans[i]++;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<n;i++){
			for(long long j=1;j<=n;j++){
				ans[j]=0;
			}
			dij(i,n);
			for(long long j=1;j<=n;j++){
				if(ans[j]==1){
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
