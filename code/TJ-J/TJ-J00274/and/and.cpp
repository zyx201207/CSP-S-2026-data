#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[100001],b[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=m;j>=1;j--){
			b[j]=max(b[i-1],a[i]&b[j]);
		}
	}
	cout<<b[n];
	return 0;
}
