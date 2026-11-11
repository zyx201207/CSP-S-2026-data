#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	int s[200005];
	char a;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>a;
	}
		if(n==1){
		cout<<0;
		return 0;
	}
	if(s[1]==1){
		cout<<n/2;
		return 0;
	}
	return 0;
} 
