#include<bits/stdc++.h>
using namespace std;
bool checkA(string a,string b){
	if(a[2] == 'A' or a[2] == 'B' or a[2] == 'C'){
		if(b[2] == 'A' or b[2] == 'B' or b[2] == 'C') return 1;
		return 0;
	}
	else{
		if(b[2] == 'D' or b[2] == 'F') return 1;
		return 0;
	}
	return 0;
}
bool checkB(string a,string b){
	if(a[2] == 'A' or a[2] == 'C'){
		if(b[2] == 'B') return 1;
		return 0;
	}
	else if(a[2] == 'B'){
		if(b[2] == 'A' or b[2] == 'C') return 1;
		return 0;
	}
	else if(a[2] == 'D'){
		if(b[2] == 'F') return 1;
		return 0;
	}
	else{
		if(b[2] == 'D') return 1;
		return 0;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a == x){
		cout<<1;
		if(b[0] == y[0] and b[1] == y[1]){
			cout<<1;
			if(checkA(b,y)){
				cout<<1;
				if(checkB(b,y)) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
