#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1005];
	string c[10];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	if(n==1){
		cout<<"0";
	} 
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}
		cout<<min(a[1],a[2]);
	}
	return 0;
}
