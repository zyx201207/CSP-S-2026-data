#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m,maxc=0,a[200010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		int sum=a[i];
		for(int x=i;x<i+m;x++) sum=sum&a[x];
		if(sum>=maxc) maxc=sum;
	}
	cout<<maxc;
	return 0;
}