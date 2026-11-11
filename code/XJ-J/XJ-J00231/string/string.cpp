#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,e;
	e=0;
	cin>>a;
	int b[a];
	string c[a];
	string d;
	for(int i=0;i<a;i++){
		cin>>b[i]>>c[i];
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b[i];j++){
			d+=c[i];
		} 
	}
	
	for(int i=0;i<d.length()/2;i++){
		if(d[i]!=d[d.length()-i]){
			e+=1;
		}
	}
	cout<<e;
} 
