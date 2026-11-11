#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],minn[200005],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		
	}
	for(int i=1;i<=n;i++){
		minn[i]=min(a[i],a[i+1]);
		maxn=max(minn[i],minn[i+1]); 
	}
	cout<<maxn;
	return 0;
}
