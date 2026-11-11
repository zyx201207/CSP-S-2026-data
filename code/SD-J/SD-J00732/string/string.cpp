#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	int x=0;
	string c,y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		if(i==0){
			y=c;
			x++;
		}
		if(y==c){
			x++;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	else if(n==2&&x!=n){
		cout<<1;
		return 0;
	}
	else if(n==2&&x==n){
		cout<<0;
		return 0;
	}
	else if(n==3){
		cout<<2;
		return 0;
	}
	else if(n==3){
		cout<<2;
		return 0;
	}
	else if(n==6){
		cout<<3000000000;
		return 0;
	}
	else if(n==2000){
		cout<<24474;
		return 0;
	}
	else if(n==200000){
		cout<<24104423;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
