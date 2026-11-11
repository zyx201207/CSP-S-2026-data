#include<bits/stdc++.h>
using namespace std;
long long maxx=0,x=0;
long long n,m;
long long a[200000+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2&&n*(n-1)/2<=2e6){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	maxx=a[n];
	for(int i=n-1;i>=n-m+1;i--)maxx=maxx&a[i];
	cout<<maxx;
	return 0;
}
