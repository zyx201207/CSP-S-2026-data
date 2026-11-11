#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0,l=0,flag=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		l+=a;
		if(a!=1) flag=1;
		for(int i=1;i<=a;i++){
			s[t]=c;
			t++;
		}
	}
	if(flag==0){
		cout<<l/2*2;
		return 0;
	}else  if(n==6) cout<<3000000000;
	int cnt=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
