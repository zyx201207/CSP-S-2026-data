#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	string c;
	int d=3;
	while(d>0){
		int i = 0;
		c[i] = d%2;
		d/=2;
	}
	//cout<<d<<"........."<<c<<endl;
	int u = c.size();
	string s;
	for(int i = u ;i>=1;i--){
		s+=c[i];
	}
	for(int i = 1 ;i<=u;i++){
		d+=(s[i]-'0')*pow(10,i);
	}
	cout<<d;
	return 0;
}
