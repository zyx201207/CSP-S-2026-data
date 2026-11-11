#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
int n,m,a[maxn],cnt[maxm];
long long ans[maxm];
bool vis[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	vector<int> nowl;
	int cnted=0;
	for(int i=n;i>=1&&cnted<m;i--){
		if(!vis[a[i]]){
			nowl.push_back(a[i]);
			for(int x:nowl){
				ans[x]+=cnt[a[i]];
			}
			vis[a[i]]=true;
			cnted++;
		}
		else{
			while(nowl[nowl.size()-1]!=a[i]&&nowl.size()>0){
				nowl.pop_back();
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}