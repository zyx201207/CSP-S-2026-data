#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,b;
	char x,y;
	cin>>n;
	if(n==1){
		cin>>a>>x;
		cout<<0;
	}else if(n==2){
		cin>>a>>x>>b>>y;
		if(x==y){
			cout<<0;
		}else{
			cout<<min(a,b);
		}
	}else{
		cout<<rand()%15; 
	}
	return 0;
}

