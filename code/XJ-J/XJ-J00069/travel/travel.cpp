#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char n,m,x,y;
	int a,b,c,d;
	cin>>n>>m;a=n*10+m;
	cin>>n>>m>>x;b=n*10+m;
	cin>>n>>m;c=n*10+m;
	cin>>n>>m>>y;d=n*10+m;
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if((x<='C'&&x>='A'&&y<='C'&&y>='A')||(x<='F'&&x>='D'&&y<='F'&&y>='D')){
				cout<<"1";
				if(abs(x-y)==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
