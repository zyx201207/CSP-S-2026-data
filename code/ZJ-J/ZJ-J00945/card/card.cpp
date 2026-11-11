#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N];
int s[N];
int lst[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(lst[a[i]]!=0){
			for(int j=lst[a[i]]+1;j<i;++j){
				s[j]=max(s[j],lst[a[i]]);
			}
		}
		lst[a[i]]=i;
	}
	memset(lst,0,sizeof lst);
	for(int j=1;j<=n;++j){
		ans[a[j]]+=j-max(s[j],lst[a[j]]);
		ans[a[j]]=max(ans[a[j]],j-s[j]);
		lst[a[j]]=j;
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
---
4 3
1 2 1 3
*/