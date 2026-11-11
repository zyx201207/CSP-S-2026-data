#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b[1000001],c[10000001];
int main(){
	freopen("ans.out","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	memset(b,255,sizeof(b));
	for(long long i=1;i<=n;i++){
		cin>>a[i];b[i]=b[i]&a[i];
	}
	m++;
	while(m--){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				c[i]=b[i]&a[j];
			}
			
		}
	}
	sort(c+1,c+n+1);
	cout<<c[n];
	return 0;
}
