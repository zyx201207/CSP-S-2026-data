#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],cnt=0;
signed main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n-1;i++){
		if(a[i]<=a[i+1]){
			cnt++;
		}
	}
	if(cnt==n-1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i; 
			}
		}
	}
	return 0;
}
/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[j]==a[i]){
				for()
			}
		}
	}
╮(￣⊿￣")╭生无可恋      ╮(￣⊿￣")╭生无可恋    _三└(┐卍 ?ω?)卍
*/
