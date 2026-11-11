#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	int x=(c_1[0]-'0')*10+c_1[1]-'0';
	int y=(c_2[0]-'0')*10+c_2[1]-'0';
	if(y==x) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	x=(s_1[0]-'0')*10+s_1[1]-'0';
	y=(s_2[0]-'0')*10+s_2[1]-'0';
	if(x==y) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	x=int(s_1[2]<='C');
	y=int(s_2[2]<='C');
	if(x==y) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	char a=s_1[2];
	char b=s_2[2];
//	cout<<"now:"<<s_1<<";";
//	cout<<int(a)<<"\n";
	if(a>b) swap(a,b);
//	cout<<a<<" "<<b<<"\n";
	if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='D'&&b=='F'){
		cout<<1;
	}else cout<<0;
	return 0;
}
//red