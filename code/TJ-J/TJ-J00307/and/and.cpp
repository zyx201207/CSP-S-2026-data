#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],b[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	cout<<a[n-m];
	return 0;
}
