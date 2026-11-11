#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],lst[N],fa[N],t[N],siz[N];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=-1;
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=n;i>=1;i--){
		if(lst[a[i]]==-1){
			lst[a[i]]=i;
		}
		else{
			fa[i]=lst[a[i]];
			siz[fa[i]]++;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i){
			t[++cnt]=i;
		}
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<fa[i]<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<=cnt;i++){
		ans[a[t[i]]]+=siz[t[i]];
//		cout<<a[t[i]]<<' '<<ans[a[t[i]]]<<endl;
		if(t[i]<n){
			siz[fa[t[i]+1]]+=siz[t[i]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
