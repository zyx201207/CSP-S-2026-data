#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N];
vector<int>tmp;
map<int,map<vector<int>,int> >mp;
void dfs(int now,vector<int> v){
	v.push_back(now);
//	for(auto t:v) cout<<t;
//	cout<<endl;
	mp[now][v]++;
	for(int i=now+1;i<=n;i++){
		if(x[i]-x[now]<=d){
			dfs(i,v);
		}
	}
}
map<int,int>mp1;
vector<int>empty;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(n<=100){
			int ans=0;
			for(int i=1;i<=n;i++){
				mp.clear();
//				cout<<"I:"<<i<<endl;
				dfs(i,empty);
				for(int j=i+1;j<=n;j++){
					mp1.clear();
					for(auto at:mp[j]){
						mp1[at.first.size()]++;
					}
					for(auto at:mp1){
						if(at.second==2){
							ans++;
//							cout<<"ANS:";
//							cout<<at.first<<endl;
						}
						break;
					}
				}
			}
			cout<<ans<<endl;
		}else{
			cout<<n*(n-1)/2<<endl;
		}
	}
	return 0;
}