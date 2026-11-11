#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,q,cnt=0;
	long long a[200001],b[200001],maxn=0,x;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		q=a[i]%10;
		for(int i=1;i<=cnt;i++){
			b[i]+=q*2;
		}
		a[i]/=10;
		cnt++; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			x=b[i] and b[j];
			maxn=max(maxn,x);
		}
	}
	cout<<maxn;
	return 0;
} 
