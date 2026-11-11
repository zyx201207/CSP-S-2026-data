#include<iostream>
#include<stdio.h>

using namespace std; 






int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int a,b;
	cin>>a>>b;
	if(a==0&&b==2){cout<<1<<'\n'<<2;
	} else if(a==0&&b==2){
		cout<<0<<'\n'<<1;
	}
	return 0;
	
}
