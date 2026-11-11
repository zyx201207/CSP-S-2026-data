#include<bits/stdc++.h>
using namespace std;
int ch[]={1,1,1,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(ch[b[2]-'A']==ch[d[2]-'A']){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
