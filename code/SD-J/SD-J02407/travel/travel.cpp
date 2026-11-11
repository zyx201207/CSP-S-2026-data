#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
ll cc,sc;
char cc2,sc2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	cc=(s1[0]-'0')*10+(s1[1]-'0');
	sc=(s2[0]-'0')*10+(s2[1]-'0');
	cc2=s1[2];
	sc2=s2[2];
//	cout<<cc<<" "<<sc<<endl;
	if(cc!=sc){
		cout<<"000";
		return 0;
	}
	cout<<"1";
/*	cout<<cc2<<" "<<sc2<<endl;
	cout<<sc2<='C'*/
	if((cc2>='A'&&cc2<='C'&&sc2>='A'&&sc2<='C')||(cc2>='D'&&cc2<='F'&&sc2>='D'&&sc2<='F')){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(int(cc2-sc2))==1){
		cout<<'1'<<endl;
		return 0;
	}
	cout<<'0';
	return 0;
}

