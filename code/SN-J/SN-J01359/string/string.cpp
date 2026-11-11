#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char c;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int g;
		cin>>g;
		cin>>c;
		for(int j=1;j<=g;j++){
			s=s+c;
		}
	}
	string d;
	for(int i=n+1;i>=0;i--){
		d+=s[i];
	}
	int cnt=0;
	for(int i=n/2;i<=n;i++){
		if(s[i]!=d[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
