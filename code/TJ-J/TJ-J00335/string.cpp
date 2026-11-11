#include<bits/stdc++.h>
using namespace std;
int main ( ){
	
	int n,a,e=1,q=0,f=1;
	cin>>n;
	char c;
	vector<char> b,d;
	
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			b[f]=c;
			f++;
		}
		for(int i=a*n;i>=1;i--){
		b[i]=d[e];
		e++;
	}
	for(int i=1;i<=a*n;i++){
		if(d[i]!=b[i]){
			q++;
		}
		
	}
	}
	
	cout<<q;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
}
