#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,shu=0,x=0;
	string s;
	string h;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long y;
		cin>>y;
		char d;
		cin>>d;
		for(int j=1;j<=y;j++){
			s[shu++]=d;
		}
	}
	for(int i=shu-1;i>=0;i--){
		if(s[i]!=s[shu-1-i]){
			x++;
		}
	}
	cout<<x/2;
	return 0;
}
