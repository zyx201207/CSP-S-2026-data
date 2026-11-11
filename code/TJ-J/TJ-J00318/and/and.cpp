#include<bits/stdc++.h>
using namespace std;
int n,m,ann,maxx;
int a[200010];
int f(int j,int k,int ans) {
	ann=ans&a[j];
	if(k==m) {
		return ans;
	}
	if(j==n+1) {
		return 0;
	}
	return max(f(j,k+1,ann),f(j+1,k,a[j]));
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	ann=a[1];
	if(n=m) {
		for(int i=1;i<=n;i++) {
			ann&=a[i];
		}
		cout<<ann;
		return 0;
	}
	if(m=1){
		cout<<maxx;
		return 0;
	}
	
	//int c=3&3;
	//cout<<c;
	cout<<f(1,1,ann);
	return 0;
}
