#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	string b;
	int n;
	cin>>n;
	int a[n],c[n];
	long long x=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b;
		if(b=="a"){
			for(int j=x;j<x+a[i];j++){
				x+=a[i];
				c[j]=1;
			}
		}
		if(b=="b"){
			for(int j=x;j<x+a[i];j++){
				x+=a[i];
				c[j]=2;
			}
		}
		if(b=="c"){
			for(int j=x;j<x+a[i];j++){
				x+=a[i];
				c[j]=3;
			}
		}
		if(b=="d"){
			for(int j=x;j<x+a[i];j++){
				x+=a[i];
				c[j]=4;
			}
		}
		if(b=="e"){
			for(int j=x;j<x+a[i];j++){
				x+=a[i];
				c[j]=5;
			}
		}
		if(b=="f"){
			for(int j=x;j<x+a[i];j++){
				x+=a[i];
				c[j]=6;
			}
		}
		if(b=="g"){
			for(int j=x;j<x+a[i];j++){
				x+=a[i];
				c[j]=7;
			}
		}
	}
	int y=0;
	if(x%2==0){
		int z=x;
		for(int i=0;i<x/2;i++){
			if(c[i]!=c[z]){
				y++;
			}
			z--;
		}
	}
	else{
		x=x-1;
		int z=x;
		for(int i=0;i<x/2;i++){
			if(c[i]!=c[z]){
				y++;
			}
			z--;
		}
	}
	cout<<y;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
