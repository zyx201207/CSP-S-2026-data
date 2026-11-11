//考号：SN-J00760  姓名：刘浩宇  学校：西安市汇知中学 
#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false);
using namespace std;
string a,b,c,d;
signed main(){
	IOS
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int x=(b[0]-'0')*10+(b[1]-'0'),y=(d[0]-'0')*10+(d[1]-'0');
	if(x!=y){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int u=b[2]-'A',v=d[2]-'A';
	if((u>2&&v<3)||(u<3&&v>2)){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(u-v)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
