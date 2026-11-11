#include<bits/stdc++.h>
using namespace std;
long long n,d,a[5005],s[5005],m[5005],sum[5005],mi,ans;
vector<int> as[5005];
int dfs(int r){
	int k=0;
	for(int i=0;i<as[r].size();i++){
		
		if(s[as[r][i]]==1e9||s[as[r][i]]==s[r]+1){
			sum[as[r][i]]+=sum[r];
		}
		if(s[as[r][i]]==1e9){
			s[as[r][i]]=s[r]+1;
		}
	}
	for(int i=0;i<as[r].size();i++){
		if(s[as[r][i]]==s[r]+1&&m[as[r][i]]==0){
			m[as[r][i]]=1;
			dfs(as[r][i]);
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]>a[i]+d) break;
				as[i].push_back(j);
				as[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				s[j]=1e9;
				sum[j]=0;
				m[j]=0;
			}
			s[i]=0;
			sum[i]=1;
			m[i]=1;
		//	cout<<i<<'\n';
			dfs(i);
			for(int j=1;j<=n;j++){
				if(sum[j]==2) ans++;
			}
		}
		for(int j=1;j<=n;j++){
			as[j].clear();
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}