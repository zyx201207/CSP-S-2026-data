#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,ans,cnt[30];
vector<int> vec[30];
bool vis[200005][30],viss[200005];
int maxw;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	maxw=-1;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
		for(int j=0;j<30;j++)
			if(a[i]&(1<<j)){
				vis[i][j]=1;
				vec[j].push_back(i);
				cnt[j]++;
				if(cnt[j]>=m) maxw=max(maxw,j);
			} 
	}
	if(maxw==-1){
		cout<<"0\n";
		return 0;
	}
	ans+=(1<<maxw);
	for(int id:vec[maxw]) viss[id]=1;
	for(int j=maxw-1;j>=0;j--){
		int cnt=0;
		for(int id:vec[maxw]){
			if(!viss[id]) continue;
			if(vis[id][j]) cnt++;
		}
		if(cnt<m) continue;
		ans+=(1<<j);
		for(int id:vec[maxw]){
			if(!viss[id]) continue;
			if(!vis[id][j]) viss[id]=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
