#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			x=b[2]-'A';
			y=d[2]-'A';
			if(x<=2){
				if(y<=2){
					cout<<1;
					if(x+y!=2) cout<<1;
					else cout<<0;
				}
				else cout<<"00";
			}
			else{
				if(y>2) cout<<"11";
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0; 
}
