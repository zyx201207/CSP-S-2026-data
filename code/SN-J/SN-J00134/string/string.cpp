#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	string m;
	int n,cnt=0;
	string b,c;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char x;
		cin>>a>>x;
		for(int j=0;j<a;j++){
			m=m+x;
		}
	}
	for(int i=0;i<m.size();i++){
		b=b+m[i];
	}
	for(int i=m.size();i>=0;i--){
		c=c+m[i];
	}
	for(int i=1;i<m.size();i++){
		if(b[i]!=c[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
