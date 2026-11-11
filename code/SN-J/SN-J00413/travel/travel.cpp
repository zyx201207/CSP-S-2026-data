#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int p,q;
int e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}else cout<<1;
	p=(b[0]-'0')*10+(b[1]-'0');
	q=(d[0]-'0')*10+(d[1]-'0');
	if(p!=q){
		cout<<"000";
		return 0;
	}
	cout<<1;
	e=b[2]-'A'+1;
	f=d[2]-'A'+1;
	if((e<=3)!=(f<=3)){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(e-f)==1)cout<<1;
	else cout<<0;
	return 0;
}
/*
X X XXX?
区喵来要打CSP-J了喵 （此处应有一个表情，但是这个考场Win+.用不了）
8:42
*/
