#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<"1";
		int xx,yy;
		xx=(x[0]-'0' )*10+x[1]-'0';
		yy=(y[0]-'0' )*10+y[1]-'0';
			if(xx==yy){
				cout<<"1";
				if(x[2]=='A'&&y[2]=='B'||x[2]=='A'&&y[2]=='C'||x[2]=='B'&&y[2]=='A'||x[2]=='B'&&y[2]=='C'||x[2]=='C'&&y[2]=='A'||x[2]=='C'&&y[2]=='B'||x[2]=='D'&&y[2]=='F'||x[2]=='F'&&y[2]=='D'){
					cout<<"1";
				if(x[2]=='A'&&y[2]=='B'||x[2]=='B'&&y[2]=='A'||x[2]=='B'&&y[2]=='C'||x[2]=='C'&&y[2]=='B'||x[2]=='D'&&y[2]=='F'||x[2]=='F'&&y[2]=='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}

	return 0;
}
