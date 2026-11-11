#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long lu,a[N];
//void dfs(int l,int r,int d){
//	if(l+1==r){
//		lu++;
//		return;
//	}
//	for(int i=l;i<r;i++){
//		if()
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
//		long long ans=0;
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				dfs(i,j,d);
//			}
//		}
		cout<<abs(a[0])<<'\n';
	}
	return 0;
}
