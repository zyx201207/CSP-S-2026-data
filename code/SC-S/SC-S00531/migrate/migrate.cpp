#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[5005];
long long  a[10005],cnt[10005];
/*void dfs(int p,int last){
	for(int i=1;i<=n;i++){
		if(i!=p&&abs(x[i]-x[p])<=d&&i!=last){
			if(a[i]>a[p]+1){
				a[i]=a[p]+1;
				cnt[i]=1;
				dfs(i,p);
			}if(a[i]==a[p]+1) cnt[i]++;
		}
	}
	return;
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		int ans=0;
			for(int k=1;k<=n;k++){
				a[k]=0;
				cnt[k]=100000000;
			}/*
			a[1]=0;
			dfs(1,0);
			*/
			
			cnt[1]=0;
			for(int E=1;E<=n;E++){
		for(int u=E;u<=n;u++){
			for(int k=u+1;k<=n;k++){
				if(abs(x[u]-x[k])<=d){
					if(cnt[k]==cnt[u]+1){
						a[k]++;
						//cout<<k<<' '<<u<<'\n';
					}
					if(cnt[k]>cnt[u]+1){
						cnt[k]=cnt[u]+1;
						a[k]=1;
					}
				}
			}
		}
		for(int k=2;k<=n;k++){
			//cout<<a[k]<<' ';
				if(a[k]==2){
					ans++;
			
					//cout<<1<<' '<<k<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}  