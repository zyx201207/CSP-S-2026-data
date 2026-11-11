#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m*(n-m+1)<1e9){
		int  _max=-1;
		for(int i=1;i<=n-m+1;i++){
			int t=a[i];
			for(int  j=i+1;j<i+m;j++) t&=a[j];
			_max=max(_max,t);
		}
		cout<<_max;
	}
	else cout<<a[n-m+1];
	return 0;
}
