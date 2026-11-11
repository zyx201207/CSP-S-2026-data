#include<bits/stdc++.h>
using namespace std;
struct kl{
	int us,sl;
};
long long c,m,n,d,q,st[500005],mi[505][505];
vector<kl> a[500005],as[505];
set<pair<long long,int> > qw;
int dij(int sa){
	for(int i=1;i<=n;i++){
		mi[sa][i]=1e18;
		if(i==sa) mi[i][i]=0;
	}
	qw.insert({0,sa});
	while(qw.size()){
		pair<long long,int> k=*qw.begin();
		int v=k.second;
		long long sum=k.first;
		for(int i=0;i<as[v].size();i++){
			if(mi[sa][as[v][i].us]>sum+as[v][i].sl){
				if(mi[sa][as[v][i].us]!=1e18){
					qw.erase({mi[sa][as[v][i].us],as[v][i].us});
				}
				qw.insert({sum+as[v][i].sl,as[v][i].us});
				mi[sa][as[v][i].us]=sum+as[v][i].sl;
			}
		}
		qw.erase(qw.begin());
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>st[i];
	}
	for(int i=1;i<=n;i++){
		int sum;
		cin>>sum;
		for(int j=1;j<=sum;j++){
			int v,s;
			cin>>v>>s;
			kl rt;
			rt.us=i;
			rt.sl=s;
			a[v].push_back(rt);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				kl w;
				w.us=a[i][k].us;
				w.sl=a[i][j].sl+a[i][k].sl;
				as[a[i][j].us].push_back(w);
				w.us=a[i][j].us;
				as[a[i][k].us].push_back(w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	long long ans;
	while(q--){
		ans=1e18;
		int l,r;
		cin>>l>>r;
		for(int j=0;j<a[l].size();j++){
			for(int k=0;k<a[r].size();k++){
				ans=min(ans,a[l][j].sl+a[r][k].sl+st[l]+st[r]+mi[a[l][j].us][a[r][k].us]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}