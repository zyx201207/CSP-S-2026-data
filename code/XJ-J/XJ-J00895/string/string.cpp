#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a=0,b=0,e=0,f=0;
	string c="",d="";
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>d;
		for(int j=0;j<b;j++){
			e++;
			c+=d;
		}
	}
	for(int i=0;i<e/2;i++){
		if(c[i]!=c[e-1-i]){
			f++;
		}
	}
	cout<<f;
	return 0;
}