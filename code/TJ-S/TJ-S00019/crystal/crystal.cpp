#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500011],b[500011];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[1]=0;
	for (int i=2;i<=n;i++){
		for (int j=1;j<=i;j++){
			b[i]+=a[i]-a[j];
		}
	}
	int maxn=0;
	for (int i=1;i<=n;i++){
		if (b[i]<=m){
			maxn=max(maxn,i);
		}
	}
	cout<<maxn;
	return 0;
} 
