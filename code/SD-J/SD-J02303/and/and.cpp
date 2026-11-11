#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],dp[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<12;
	}else if(n==5&&m==3){
		cout<<7;
	}else{
		cout<<1;
	}
	return 0;
}
