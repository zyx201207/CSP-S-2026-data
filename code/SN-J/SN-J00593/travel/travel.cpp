#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	char b,d;
	cin>>a>>c>>b>>d;
	if(a==c){
	    cout<<1;
		
	}
	else{
		cout<<0;
	}
	int x=b/10;
	int y=d/10;
	if(a==b&&x==y){
		cout<<1;
	}
	int num=b%10;
	int sum=d%10;
	if(num+1==sum){
		cout<<1<<1;
	}
	
	
	
	
	return 0;
}
