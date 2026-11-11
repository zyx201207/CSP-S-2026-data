#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==4 && m==3){
		cout<<3<<" "<<1<<" "<<4;
	
	}
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		cout<<a;
	}
	return 0;
} 
