#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,a[N];
int ans=-1;
int And(int a,int b){
	return (int)(a&b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){ 
			ans=max(ans,And(a[i],a[j]));
		}
	}
	cout<<ans; 
	return 0;
}
