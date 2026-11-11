#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int cnt[300005];
int vis[500005];
map<int,int> mp;
void solve1(){
	for(int i = 1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j = 1;j<=m;j++) mp[j] = 0;
		for(int j = i;j<=n;j++){
			mp[a[j]]+=1;
			if(mp[a[j]]==2){
				mp[a[j]] = 1;
				int flag = 0;
				for(int k = i; k<=j-1;k++){
					if(flag==1&&vis[k]==0){
						mp[a[k]]--;
						vis[k] = 1;
					}
					if(a[k]==a[j]&&vis[k]==0){
						vis[k] = 1;
						flag = 1;
					}
				}
			}
		}
		for(int j = 1;j<=m;j++){
			if(mp[j] == 1) cnt[j]++;
		}
		//for(int j = 1;j<=m;j++) cout << cnt[j] << " ";
		//cout << "\n";
	}
	for(int i = 1;i<=m;i++) cout << cnt[i] << " ";
	return;
}
void solve2(){
	for(int i = 1;i<=n;i++) mp[a[i]]++;
	for(int i = 1;i<=n;i++){
		if(i!=1) mp[a[i-1]]--;
		for(int j = 1;j<=m;j++){
			if(mp[j]%2==1) cnt[j]++;
		}
	}
	for(int i = 1;i<=m;i++) cout << cnt[i] << " ";
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	if(n<=500&&m<=200) solve1();
	else solve2();
	return 0;
}
