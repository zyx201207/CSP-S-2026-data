#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-1,j=m;j>0;i--,j--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
