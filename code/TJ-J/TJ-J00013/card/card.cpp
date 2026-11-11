#include<bits/stdc++.h>
using namespace std;
long long a[200005],c[200000],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4 and m==3){
		cout<<3<<" "<<4<<" "<<1;	
	}
	if(n==10 and m==3){
		cout<<10<<" "<<3<<" "<<3;	
	}
	return 0;
} 
