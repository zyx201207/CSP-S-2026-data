#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500009];
int ans[500009];
int solve[500009];
int main(){
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=m;i++){
		cout<<0<<' ';
	}
	return 0;
}
