#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(pow(n,m)>1000){
		cout<<a[n-m+1];
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
