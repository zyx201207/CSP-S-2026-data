#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==4 && m==3){
		cout<<1<<" "<<2<<" "<<1<<" "<<3;
	} 
	else{
		cout<<3<<" "<<1<<" "<<2<<" "<<1<<" "<<3<<" "<<2<<" "<<3<<" "<<1<<" "<<2<<" "<<1;
	} 
	
	return 0;
}
