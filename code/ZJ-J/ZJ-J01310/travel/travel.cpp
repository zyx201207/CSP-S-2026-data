#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<"1";
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<"1";
			if('A'<=x[2]&&x[2]<='C'&&'A'<=y[2]&&y[2]<='C'||'D'<=x[2]&&x[2]<='F'&&'D'<=y[2]&&y[2]<='F'){
				cout<<"1";
				if('A'<=x[2]&&x[2]<='C'&&'A'<=y[2]&&y[2]<='C'&&(x[2]+1==y[2]||y[2]+1==x[2])) cout<<"1";
				else if(x[2]=='D'&&y[2]=='F'||y[2]=='D'&&x[2]=='F') cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
