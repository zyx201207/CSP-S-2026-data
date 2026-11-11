#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string b;
	int cnt=0,m=0;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		m+=a;
		for(int i=1;i<=a;i++) b+=c;
	}
	for(int i=0;i<=m/2;i++){
		if(b[i]!=b[m-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
