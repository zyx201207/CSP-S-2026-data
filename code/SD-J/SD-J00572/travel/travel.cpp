#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int p=b[0]*10+b[1];
	int q=d[0]*10+d[1];
	if(p!=q){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(b[2]>='A' && b[2]<='C'){ 
		if(d[2]>='D' && d[2]<='F'){
			cout<<"00";
			return 0;
		}
		cout<<1;
		if(b[2]+1==d[2] || b[2]-1==d[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(b[2]>='D' && b[2]<='F'){ 
		if(d[2]>='A' && d[2]<='C'){
			cout<<"00";
			return 0;
		}
		cout<<11;
	}
	return 0;
}
