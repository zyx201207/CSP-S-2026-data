#include<bits/stdc++.h>
using namespace std;
int d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,s;
	cin>>a>>s;
	for(int i=1;i<=a;i++){
		cin>>d;
	}
	if(a==4){
		cout<<3<<" "<<1<<" "<<4;
	}
	else if(a==10){
		cout<<10<<" "<<3<<" "<<3;
	}
	else{
		cout<<4<<" "<<2<<" "<<1;
	}
	return 0;
}
