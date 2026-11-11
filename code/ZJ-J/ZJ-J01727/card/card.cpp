#include<bits/stdc++.h>
#define int long long
using namespace std;
bool use[300005];
int n,m;
int a[500005],ans[500005];
vector<int> now;
void game(int l){
	now.clear();
	memset(use,0,sizeof(use));
	for(int i=l;i<=n;i++){
		now.push_back(a[i]);
		if(use[a[i]]==1){
			use[a[i]]=0;
			now.pop_back();
			while(now.back()!=a[i]){
				use[now.back()]=0;
				now.pop_back();
			}
			now.pop_back();
			now.push_back(a[i]);
			use[a[i]]=1;
		}
		else{
			use[a[i]]=1;
		}
	}
	for(int i=0;i<now.size();i++){
		ans[now[i]]++;
	}
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
