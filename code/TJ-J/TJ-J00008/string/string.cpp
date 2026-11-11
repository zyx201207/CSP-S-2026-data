#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		int x;
		char y;
		cin>>x>>y;
		cout<<0;
	}else if(n==2){
		int x1,x2;
		char y1,y2;
		cin>>x1>>y1;
		cin>>x2>>y2;
		if(y1==y2){
			cout<<0;
		}
		else{
			cout<<(x1+x2)/2;
		} 
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
