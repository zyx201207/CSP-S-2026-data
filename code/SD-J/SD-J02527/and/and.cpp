#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005];
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
	}
	if(m==n){
		cout<<a[1];
		}
	if(a[n]-a[n-m]<=8){
		cout<<a[n-m];
	}else{
		cout<<a[n-m];
	}
	
	return 0;
}
