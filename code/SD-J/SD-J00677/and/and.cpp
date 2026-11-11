#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1010101];
bool cmp(int x,int y){
	return x>y;
}
vector<int> v;
int vis[1010101];
int n,m,sum=-1e18;
void dfs(int step){
	if(step==m){
		int ans=v[0];
//		cout <<"\n";
		for(auto i:v){
			ans&=i;
//			cout <<i<<" ";
		}
//		cout <<"\n";
		sum=max(sum,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			v.push_back(a[i]);
			vis[i]=1;
			dfs(step+1);
			vis[i]=0;
			v.pop_back();
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		int cnt=__builtin_popcountll(a[i]);
		int kk=log2(a[i]+1);
	//	cout <<"\n"<<kk<<"\n";
		if(cnt!=kk){
			f=0;
		}
	}
	if(n<=22){
		dfs(0);
		cout <<sum;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout <<a[1];
		return 0;
	}
	if(m==2){
		int ans=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout <<ans;
		return 0;
	}
	if(f){
		cout <<a[m];
		return 0;
	}
	return 0;
}
