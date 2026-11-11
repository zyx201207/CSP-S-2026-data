#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[100005],it=0;
vector<vector<int>> ans;
map<pair<int,int>,int> aaa;
map<pair<int,int>,int> mm;
void dfs(int u,vector<int> aa){
	ans.push_back(aa);
	for(int i=u+1;i<=n;i++){
		if(abs(a[i]-a[u])<=d){
			aa.push_back(i);
			dfs(i,aa);
			aa.pop_back();
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==1||c==2||c==0){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			it=0;
			for(int i=1;i<=n;i++){
				dfs(i,{i});
			}
			for(auto out:ans){
				int len=1,sto=0,sss=0;
				for(auto x:out){
					if(len==1)sto=x,len++;
					sss=x;
				}
				if(mm[{sto,sss}]==0)mm[{sto,sss}]=100000000;
				mm[{sto,sss}]=min(mm[{sto,sss}],(int)out.size());
			}
			for(auto out:ans){
				int len=1,sto=0,sss=0;
				for(auto x:out){
					if(len==1){
						sss=x;
						len++;
					}
					sto=x;
				}
				if(out.size()!=mm[{sss,sto}])continue;
				aaa[{sss,sto}]++;
			}
			ans.clear();
			int lla=0;
			for(auto out:aaa){
				if(out.second==2){
					
					lla++;
				}
			}
			cout<<lla<<"\n";
			aaa.clear();
			mm.clear();
		}
	}else{
		while(t--){
			cin>>n>>d;
			int ct=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				ct=a[i]-a[i-1];
			}
			int ans=n/ct;
			cout<<n-ans<<"\n";
		}
	}
	return 0;
}