#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char x,y;
	int a,b,l,r; 
	cin>>a>>l>>x>>b>>r>>y;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	} 
	
	if(l==r) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	
	if(x<='C'&&y<='C') cout<<1;
	else if(x>='D'&&y>='D') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	
	if(x=='C'&&y=='D') cout<<0;
	else if(x=='D'&&y=='C') cout<<0;
	else if(x+1==y) cout<<1;
	else if(y+1==x) cout<<1;
	else cout<<0;
	return 0;
}
