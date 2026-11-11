#include <bits/stdc++.h>
using namespace std;
int  a[1001];
int  b[1001];
int  c[1001];
int main(){
	int n,m;
	string p;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		b[i]+=a[i];
		int g=b[i];
		while(g!=0){
			c[i]=g%2;
			p+=c[i];
			g/=2;
			
			
		}	
	reverse(p.begin(),p.end());
}
cout<<p;
	return 0;
}
