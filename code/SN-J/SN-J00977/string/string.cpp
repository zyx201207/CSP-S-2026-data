#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[20005];
	string c[20005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(c[0]==c[n-1]){
		cout<<"0";
	}
	if(c[0]!=c[n-1]){
		cout<<a[n-1]+1;
	}
	return 0;
}
