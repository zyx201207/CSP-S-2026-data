#include<iostream>
#include<vector>
using namespace std;
//T3
//migrate
//pts=[24,40] 
#define int long long
const int MAXN=2e18+7;
int n,d,c,t,tmp;
int a[200005];
int ans[200005],cnt[200005];
vector<int> g[200005];
void dfs(int now,int c){
	if(c<ans[now]){
		ans[now]=c;
		cnt[now]=1;
	}else if(c==ans[now]){
		cnt[now]++;
	}else{
		return;
	}
	for(int i=0;i<g[now].size();i++){
		dfs(g[now][i],c+1);
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate3.in","r",stdin);
//	freopen("test.ans","w",stdout);
	cin>>c>>t;
	for(;t--;){
		tmp=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(;!g[i].empty();){
				g[i].pop_back();
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[j]=MAXN;
				cnt[j]=0;
			}
			dfs(i,0);
			for(int j=1;j<=n;j++){
//				cout<<cnt[j]<<' ';
				if(cnt[j]==2){
					tmp++;
				}
			}
//			cout<<endl;
		}
		cout<<(tmp/2)<<endl;
	}
	return 0;
} 
/*
Oct31==Dec25?
*/
