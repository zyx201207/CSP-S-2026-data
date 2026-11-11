#include<bits/stdc++.h>
using namespace std;
char c[5][10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<3;i++)
		for(int j=1;j<=5;j++)cin>>c[i][j];
	if((c[1][1]!=c[2][1])||(c[1][2]!=c[2][2])){
		cout<<"0000";
		return 0;
	}
	if((c[1][3]!=c[2][3])||(c[1][4]!=c[2][4])){
		cout<<"1000";
		return 0;
	}
	if((c[1][5]<'D'&&c[2][5]>'C')||(c[2][5]<'D'&&c[1][5]>'C')){
		cout<<"1100";
		return 0;
	}
	if(c[1][5]-c[2][5]!=1&&c[1][5]-c[2][5]!=-1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
