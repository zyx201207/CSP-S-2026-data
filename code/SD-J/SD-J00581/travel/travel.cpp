#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool flag=0;
	if(a==c){
		f[0]=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		f[1]=1;
	}else{
		cout<<1000;
		return 0;
	}
	if(b[2]=='D'){
		if(d[2]=='F'){
			cout<<1111;
			return 0;
		}
		else{
			cout<<1100;
			return 0;
		}
	}
	else if(b[2]=='F'){
		if(d[2]=='D'){
			cout<<1111;
			return 0;
		}
		else{
			cout<<1100;
			return 0;
		}
	}
	else if(b[2]=='A'){
		if(d[2]=='B'){
			cout<<1111;
			return 0;
		}
		if(d[2]=='C'){
			cout<<1110;
			return 0;
		}
		if(d[2]=='D'){
			cout<<1100;
			return 0;
		}
		if(d[2]=='F'){
			cout<<1100;
			return 0;
		}
	}
	else if(b[2]=='B'){
		if(d[2]=='A'){
			cout<<1111;
			return 0;
		}
		if(d[2]=='C'){
			cout<<1111;
			return 0;
		}
		if(d[2]=='D'){
			cout<<1100;
			return 0;
		}
		if(d[2]=='F'){
			cout<<1100;
			return 0;
		}
	}
	else if(b[2]=='C'){
		if(d[2]=='B'){
			cout<<1111;
			return 0;
		}
		if(d[2]=='A'){
			cout<<1110;
			return 0;
		}
		if(d[2]=='D'){
			cout<<1100;
			return 0;
		}
		if(d[2]=='F'){
			cout<<1100;
			return 0;
		}
	}
	return 0;
}
