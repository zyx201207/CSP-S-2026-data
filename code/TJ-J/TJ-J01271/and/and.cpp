#include<bits/stdc++.h>
using namespace std;
long long a;
long int v[200005];
long int n,V;
int qwe(long int a,long int b,long int c){
	if(c>V||a>n){
		return 0;
	}
	if(c==V){
		return b;
	}
//	if(a=n&&c!=V){
//		return 0;
//	}
	return max(qwe(a+1,b,c),qwe(a+1,b&v[a+1],c+1));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>V;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=V;j>=1;j--){
//			dp[j]=max(dp[j-1]&v[i],dp[j]);
//		}
//	}
	cout<<qwe(0,-1,0);
	return 0;
}
