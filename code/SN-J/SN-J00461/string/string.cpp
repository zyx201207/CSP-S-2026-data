#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>n;
	for(int i=0;i<2*n;i++){
		cin>>s[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]==s[i+2]){
			cnt++;
		}
	}
	if(cnt==n){
		cout<<0;
	}	
	return 0;
}
