#include<bits/stdc++.h>
using namespace std;
int a[200000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k=0;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	k=a[1];
	//for(int i=1;i<=n;i++) cout<<a[i];
	for(int i=2;i<=m;i++){
		k=(k & a[i]);
		
	}
	cout<<k;
	return 0;
} 
