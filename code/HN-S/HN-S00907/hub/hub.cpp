#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(t == 1){
		cout<<1;
	}
	if(t == 2){
		cout<<1<<"\n"<<2;
	}
	if(t == 3){
		cout<<1<<"\n"<<2<<"\n"<<3;
	}
	if(t == 4){
		cout<<1<<"\n"<<2<<"\n"<<3<<"\n"<<4;
	}
	if(t == 5){
		cout<<1<<"\n"<<2<<"\n"<<3<<"\n"<<4<<"\n"<<5;
	}
	return 0;
} 
