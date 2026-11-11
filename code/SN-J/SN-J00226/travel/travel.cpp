#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		int x=(b[0]-'0')*10+(b[1]-'0');
		int y=(d[0]-'0')*10+(d[1]-'0');
		if(x==y){
			cout<<1;
			char c1=b[2],c2=d[2];
			if((c1=='A' || c1=='B' || c1=='C') && (c2=='A' || c2=='B' || c2=='C')){
				cout<<1;
				if(abs(c1-c2)==1)cout<<1;
				else cout<<0;
			}else if((c1=='D' || c1=='F') && (c2=='D' || c2=='F')){
				cout<<"11";
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
