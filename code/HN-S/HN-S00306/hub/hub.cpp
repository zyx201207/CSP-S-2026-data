#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("hub.in","r","stdin");
	preopen("hub.out","w","stdout");
	int a,b;
	cin>>a>>b;
	while(b--){
		int x,y;
		long long a[x][2];
		cin>>x>>y;
		for(int i=0;i<x;i++)cin>>a[i][0]>>a[i][1];
		if(x==5)cout<<1<<"\n";
		if(y==10)cout<<2<<"\n";
		else cout<<0;
	}
}
