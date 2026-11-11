#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++){
		int sum=2147483647;
		for(int j=i;j<=i+m-1;j++){
			sum&=a[j];
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx;
	return 0;
} 
