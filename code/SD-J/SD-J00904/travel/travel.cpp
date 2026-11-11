#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char x[1000],y[1000];
	cin>>a>>x;
	cin>>b>>y;
	if (a==b){
		cout<<"1";
		if (x[0,1]==y[0,1]){
			cout<<"1";
			if(x[2]="F"&&x[2]-y[2]==2){
				cout<<"11";
				}
			if(x[2]="B"||"A"&&x[2]-y[2]==1||x[2]-y[2]==-1){
				cout<<"11";
				}
				if(x[2]="A"&&x[2]-y[2]==-2){
					cout<<"10";
				}
	}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
