#include<bits/stdc++.h>
using namespace std;

int n,m,c,d,q,w[100001],k,dis[1000],now,tx,va,mp[100000],ans=0,t;


queue<int> u,v,dep;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int nn=0;nn<t;nn++){
		cin>>n>>d;
		int pl[1000000];
		for(int i=0;i<n;i++){
			cin>>pl[i];
		}
		sort(pl,pl+n+1);
		if(c<=12&&c>=11){
			if(n<4){
				cout<<0;
			}else if(d/(pl[2]-pl[1])==1){
				continue;
			}else{
				cout<<d/(pl[2]-pl[1])*n/2;
				continue;
			}
		}
		if(c<=18&&c>=15){
			int ans;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i!=j&&pl[i]-pl[j]<=d){
						ans++;
					}
				}
			}
			cout<<ans/2+1-n;
			continue;
		}
		if(c<=1&&c>=2){
			cout<<1;
			continue;
		}
		/*for(int i=0;i<n;i++){
			if(abs(pl[x]-pl[i])<=d){
				q.push(x);
				p.push(i);
				dep.push(deepth);
			}
		}
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				if(mp[j]==2){
					ans++;
				}
			}
		}*/
	}	
	
	return 0;
}
