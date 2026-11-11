#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2005];
int main(){
	preopen("and.in","r",stdin);
	preopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	
	return 0;
}
