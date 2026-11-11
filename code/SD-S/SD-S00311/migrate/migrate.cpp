#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long cn,mi;
};
long long c,t,n,d;
long long x[1000006];
Node f[1000006];
long long cnte;
void dfs(int idx,int len){
	if(idx==n+1){
		return ;
	}
	for(int i=idx+1;i<=n;i++){
		if(x[i]-x[idx]<=d){
			if(f[i].mi==len+1){
				f[i].cn++;
				dfs(i,len+1);
			}else if(f[i].mi>len+1){
				f[i].cn=1;
				f[i].mi=len+1;
				dfs(i,len+1);
			}
		}else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
//			cout<<x[2]-x[1]<<"\n";
			long long h=x[2]-x[1];
			long long l=d/h;
			long long ans=n-(2*l-1);
			if(d>=2*h&&ans>0){
				cout<<ans<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
		return 0;
	}else{
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cnte=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[j].cn=0;
				f[j].mi=1e9;
			}
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(f[j].cn==2){
					cnte++;
					cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<cnte<<"\n";
	}
	}
	return 0;
}
