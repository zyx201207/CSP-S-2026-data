#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[1]==d[1]){
			cout<<1;
			if(b[2]<='C'&&d[2]<='C'){
				cout<<1;
				int x=b[2]-'A';
				int y=d[2]-'A';
				if(abs(x-y)<=1)cout<<1;
				else cout<<0;
			}
			else if(b[2]>='D'&&d[2]>='D')cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}