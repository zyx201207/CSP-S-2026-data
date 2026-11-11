#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	int x,y;
	x=(c[0]-'0')*10+(c[1]-'0');
	y=(d[0]-'0')*10+(d[1]-'0');
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if(c[2]<='C'&&d[2]<='C'){
				cout<<1;
				if(abs(c[2]-d[2])==1)cout<<1;
				else cout<<0;
			}else if(c[2]>'C'&&d[2]>'C'){
				cout<<"11";
			}else cout<<"00";
		}else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}
