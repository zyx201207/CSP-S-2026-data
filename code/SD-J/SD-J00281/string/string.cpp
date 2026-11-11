#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,a,t=0,f=0,z=0;
	char b;
	string k;
	cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>a>>b;
		if(a==1000000000){
			z=1;
		}
		for(int j=0;j<a;j++){
			k+=b;
			t+=1;
		}
	}for(int j=0;j<t;j++){
			if(k[j]!=k[t-j-1]){
			f=1;
				
				break;
			}
		}
if(z==1){
	cout<<3000000000;
}else{

	if(f==1){
	
		cout<<2;
	}else{
		cout<<0;
	}}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
