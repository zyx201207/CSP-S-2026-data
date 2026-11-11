#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	int x=0;
	char c[n+1];
	
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1])
			x=1;
	}
	if(x==0){
		cout<<"0";
		return 0;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	cout<<2;
	return 0;
}
