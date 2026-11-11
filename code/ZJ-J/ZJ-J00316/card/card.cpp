#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
	int n,m;
bool A(){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1])return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(A()){
//		map<int,int>mp;
		int s[N];
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				s[a[i-1]]=i-1;
			}
		}
		for(int i=1;i<=m;i++)cout<<s[i]<<' ';
		return 0;
	}
	map<int,int>ans;
		for(int i=1;i<=n;i++){
			map<int,int>mp;
			for(int j=i;j<=n;j++){
				mp[a[j]]++;
				if(mp[a[j]]>1){
					int o;
					for(int k=i;k<j;k++)if(a[k]==a[j]){
						o=k;
					}
					for(int k=o;k<j;k++){
						mp[a[k]]--;
					}
				}
			}
			for(int j=1;j<=m;j++){
				if(mp[j]>0)
					ans[j]+=mp[j];
			}
		}
			for(int j=1;j<=m;j++){
				cout<<ans[j]<<' ';
			}
	return 0;
}
/*
4 3 1 2 1 3


*/
