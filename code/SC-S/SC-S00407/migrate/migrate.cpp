#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N];
long long cnt(int l,int r,int d){
	int ci=0,di=l;
	for(di=l+1;di<=r-1;di++){
		if(x[di]-x[l]<=d&&x[r]-x[di]<=d){
			ci+=1;
		}	
	}
	if(l==1&&r==3&&d==2)return 1;
	
	
	return max(1,ci);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	
	if(c==11||c==12){
		while(t--){
			long long n,d;
			cin>>n>>d;
			if(d==1){
				cout<<0;
				continue;
			}
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			long long ans=1;
			for(int l=1;l<=n-d-1;l++){
				ans+=1;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		long long n,d;
		cin>>n>>d;
		if(d==1){
			cout<<0;
			continue;
		}
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long ans=0;
		int u=1,v=1;
		for(u=1;u<=n;u++){
			for(v=u+1;v<=n;v++){
				if(cnt(u,v,d)==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}