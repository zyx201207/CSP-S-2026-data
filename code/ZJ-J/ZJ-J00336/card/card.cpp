//DONT FORGET TO MOVE!!!
//DONT FORGET TO MOVE!!!
//DONT FORGET TO MOVE!!!
//DONT FORGET TO MOVE!!!
//DONT FORGET TO MOVE!!!
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int nxt[N];
int b[N];
int lst[N];
bool flag[N];
int ans[N],f[N];
int find(int x){
	int nowx=x;
	while(f[x]!=x){
		x=f[x];
	}
	while(f[nowx]!=nowx){
		int nxt=f[nowx];
		f[nowx]=x;
		nowx=nxt;
	}
	return x;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(b,0x3f,sizeof b);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=i;
	for(int i=n;i>=1;i--){
		if(b[a[i]]!=0x3f3f3f3f) f[i]=b[a[i]];
		b[a[i]]=i;
//		cout<<f[i]<<" ";
	}
//	return 0;
	for(int i=1;i<=n;i++){
		int now=i;
		while(now<=n){
			now=find(now);
			ans[a[now]]++;
			now++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
//green/yellow
//be like CSP2025
//n^3, 15+rand pts
//Where's DP?
//O(n)?
//pdt 100+100+100+100