#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],t1[];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0){
		cout<<a[n/2];	
	}else{
		cout<<a[n/2+1];
	}
	
	return 0;
} 

