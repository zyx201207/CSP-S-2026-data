#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010];
int n,d;
vector<int> tmp;
int maxl=0x3f3f3f3f;
void dfs(int pos,int cnt,int end){
	if(pos==end){
		tmp.push_back(cnt);
		maxl=min(maxl,cnt);
	}
	if(cnt>maxl) return;
	else{
		for(int i=pos+1;a[i]-a[pos]<=d&&i<=end;i++){
			dfs(i,cnt+1,end);
		}
	}
}
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			maxl=0x3f3f3f3f;
			tmp={};
			dfs(j,0,i);
			int tttm=0;
			//cout<<"------- "<<j<<" "<<i<<endl;
			for(int i=0;i<tmp.size();i++){
				//cout<<"debug  "<<tmp[i]<<endl;
				if(maxl==tmp[i]){
					tttm++;
				}
			}
			if(tttm==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int xxx=0;xxx<t;xxx++){
		solve();
	}	
	return 0;
}
