#include<bits/stdc++.h>
using namespace std; 
bool check(string a,string b){
	for(int i=0;i<=1;i++){
		if(a[i]!=b[i])return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,x,y;
	cin>>c>>s>>x>>y;
	if(check(c,x)){
		cout<<1;
		if(check(s,y)){
			cout<<1;
			if((s[2]<='C' && y[2]<='C')){
				cout<<1;
				if((s[2]=='A' && y[2]=='B') || (s[2]=='B' && (y[2]=='A' || y[2]=='C')) || (s[2]=='C' && y[2]=='B'))cout<<1;
				else cout<<0;
			}
			else if((s[2]>='D' && y[2]>='D')){
				cout<<1;
				if((s[2]=='D' && y[2]=='F') || (s[2]=='F' && y[2]=='D'))cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
