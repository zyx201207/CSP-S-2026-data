#include<bits/stdc++.h>
using namespace std;
bool getbit(int x, int d){
	return x>>d&1;
}
int ans=0,n,m;
const int N=2e5+10,wN=15000+10;
int a[N],t[N],dp[wN][wN];
bool wst[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==n){
		ans=INT_MAX;
		for(int i=0;i<n;i++) ans&=a[i];
		cout<<ans;return 0;
	}
	if(n>wN){cout<<0;return 0;}
	for(int ini=0;ini<n;ini++){
//		if(wst[ini]) continue;
		memset(wst,0,sizeof wst);
		wst[ini]=true;
		int now=a[ini];
		for(int i=1;i<m;i++){
			int ma=0,ma_j=0;
			for(int j=0;j<n;j++){
				if(wst[j]) continue;
				int tmp=now&a[j];
				if(tmp>ma) ma=tmp,ma_j=j;
			}
			now=ma,wst[ma_j]=true;
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}