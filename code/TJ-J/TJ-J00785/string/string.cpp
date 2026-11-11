#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(s[i]==s[i-1]) cnt++;
		
	}
	if(cnt==n-1){
		cout<<0;
		return 0;
	}
	else{
		cout<<n-1;
	}
	return 0;
} 
