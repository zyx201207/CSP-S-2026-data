#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	bool x1=0,x2=0,x3=0;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
		x1=1;
		if(a1[0]==b1[0]&&a1[1]==b1[1]&&x1==1){
			cout<<1;
			x2=1;
			if((((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'))||((a1[2]=='D'||a1[2]=='F')&&(b1[2]=='D'||b1[2]=='F')))&&x2==1){
				cout<<1;
				x3=1;
				if((a1[2]-b1[2]==1||b1[2]-a1[2]==1)&&x3==1) cout<<1;
				else cout<<"0";
				}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
