#include<bits/stdc++.h>
using namespace std;
int a,c,e,f;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b,cin>>c>>d;
	e=(b[0]-'0')*10+b[1]-'0',f=(d[0]-'0')*10+d[1]-'0';
	if(a==c){
		cout<<1;
		if(e==f){
			cout<<1;
			if(b[2]<'D'&&d[2]<'D'||b[2]>'C'&&d[2]>'C'){
				cout<<1;
				if(b[2]+1==d[2]||d[2]+1==b[2])cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
