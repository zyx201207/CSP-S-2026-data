#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	long long maxl=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		long long sum=a[i];
		for(int p=i+1;p<=n-m+1;p++){
			for(int j=i+1;j<=m+i-1;j++){
				sum&=a[j];
			}
			maxl=max(maxl,sum);
		}
				
		
	}
	cout<<maxl;
	return 0;
}