#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n=1){
		cout<<a[0];
	}
	else{
		cout<<a[n];
	}
	return 0;
}
