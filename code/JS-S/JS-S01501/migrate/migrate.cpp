#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int c,t,n,d,x[2000010],a[2000010];
vector<int>g[2000010];
signed main(){
	freopen("migrate,in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n;
		map<int,bool>mp;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			mp[x[i]]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=d;j++){
				if(mp[x[i]+j]==1){
					a[x[i]+j]++;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			cout<<a[i]<<' ';
			if(a[i]==2){
				cnt++;
			}
		}
		cout<<(cnt+1)/2<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
