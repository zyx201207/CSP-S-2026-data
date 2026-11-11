#include<bits/stdc++.h>
using namespace std;
long long d=1;
int n,c,f=0;
string a,b="",e="";
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>a;
		for(int o=0;o<c;o++){
			b+=a;
			f+=1;
		}
		
	}
	for(int i=f;i>0;i--){
		e[f-i]=b[i];
	}
	for(int i=0;i<f;i++){
		if(e[i]!=b[i]){
			d+=1;
		}
	}
	cout<<d/2;
	return 0;
}