#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out", "w",stdout);
	string r,x,r1,x1;
	cin>>r1;
	cin>>r;
	cin>>x1;
	cin>>x;
	cout<<x<<" "<<x1<<" "<<r<<" "<<r1;
	if(x1[1]!=r1[1]||x1[0]!=r1[0]){
		cout<<"0000";
		return 0;
		
	}
	cout<<"1";
	
	if(r[0]==x[0]&&r[1]==x[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char d='D';
	if(x[2]=='D'&&r[2]=='C'){
		cout<<"00";
		return 0;
		
	}
	if(x[2]=='C'&&r[2]=='D'){
		cout<<"00";
		return 0;
	}
	cout<<1;
		//	cout<<" "<<(r[2]-1==x[2])<<" ";
		//	cout<<r[2]+1<<" ";

	if((r[2]-1==x[2])||(r[2]+1==x[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
