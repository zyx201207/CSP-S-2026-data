#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m,ans=-1*N;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-3;j++){
			int x;
			x=a[j]&a[j+1]&a[j+2];
			ans=max(ans,x);
		}
	}
	cout<<ans;
	return 0;
}
 
