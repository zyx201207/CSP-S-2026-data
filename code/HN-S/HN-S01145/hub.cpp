#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,r,mi,ma,num,a[1000010],b[1000010],c[1000010];
vector<long long> v[1000010];
void zhi(long long shu,long long shu2,long long shu3){
	a[shu]=min(a[shu],shu3);
	for(int i=0;i<v[shu].size( );i++){
		if(v[shu][i]==shu2) continue;
		zhi(v[shu][i],shu,shu3+1);
	}
	return;
}
void zhi2(long long shu){
	c[shu]=1;
	for(int i=0;i<v[shu].size( );i++){
		if(b[v[shu][i]]==0||c[v[shu][i]]) continue;
		zhi2(v[shu][i]);
	}
	return;
}
int main(  ){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>l>>r;
			v[l].push_back(r);
			v[r].push_back(l);
		}
		mi=1e9;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				a[j]=1e9;
				b[j]=0;
				c[j]=0;
			} 
			num=0;
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i){
					b[j]=1;
					num++;
					if(num>m) break;
					zhi(j,0,0);
				}
			}
			if(num>m) continue;
			num=0;
			for(int j=1;j<=n;j++){
				if(b[j]==0||c[j]) continue;
				num++;
				zhi2(j);
			} 
			if(num>2) continue;
			ma=0;
			for(int j=1;j<=n;j++){
				ma=max(ma,a[j]);
			}
			mi=min(mi,ma);
		}
		cout<<mi<<"\n";
		for(int i=1;i<=n;i++){
			v[i].clear( );
		}
	}
	return 0;
}
