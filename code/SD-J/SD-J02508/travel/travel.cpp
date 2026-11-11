#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
	}else{
		cout<<"1000"<<endl;
		return 0;
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		}else{
			cout<<"1100"<<endl;
			return 0;
		}
	}else{
		if(d[2]=='D'||d[2]=='F'){
		}else{
			cout<<"1100"<<endl;
			return 0;
		}
	}
	if(b[2]=='A'){
		if(d[2]=='B'){
		}else{
			cout<<"1110"<<endl;
			return 0;
		}
	}else if(b[2]=='B'){
		if(d[2]=='A'||d[2]=='C'){
		}else{
			cout<<"1110"<<endl;
			return 0;
		}
	}else if(b[2]=='C'){
		if(d[2]=='B'){
		}else{
			cout<<"1110"<<endl;
			return 0;
		}
	}else if(b[2]=='D'){
		if(d[2]=='F'){
		}else{
			cout<<"1110"<<endl;
			return 0;
		}
	}else if(b[2]=='F'){
		if(d[2]=='D'){
		}else{
			cout<<"1110"<<endl;
			return 0;
		}
	}
	cout<<"1111"<<endl;
	return 0;
}
