#include<bits/stdc++.h>
using namespace std;
int pt[300005];
bool vis[300005];
int card[500005];
int st[500005],topp;
int ans[300005];
void clearr(int toppp,int cdnum);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> card[i];
	}
	for(int q = 1; q <= n; q++){
		topp = 0;
		memset(st,0,sizeof st);
		memset(vis,0,sizeof vis);
		memset(pt,-1,sizeof pt);
		for(int i = q; i <= n; i++){
			if(vis[card[i]]){
				clearr(topp,card[i]);
				topp = pt[card[i]]-1;
				topp++;
				st[topp] = card[i];
			} 
			else {
				topp++;
				st[topp] = card[i];
				vis[card[i]] = true;
				pt[card[i]] = topp;
			}
		}
		for(int i = 1; i <= topp; i++){
			ans[st[i]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
void clearr(int toppp,int cdnum){
	for(int i = pt[cdnum]+1; i <= toppp; i++){
		vis[st[i]] = 0;
		pt[st[i]] = -1;
	}
	return;
}
