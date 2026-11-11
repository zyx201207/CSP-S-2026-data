#include<bits/stdc++.h>
#define int long long
using namespace std;
string cr,sr,cx,sx;
int shu(string s){
	int res=0;
	int ji=1;
	for(int i=s.size()-2;i>=0;i--){
		res+=((s[i]-'0')*ji);
		ji*=10;
	}
	return res;
}
bool check(){
	if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='A'&&sx[2]=='C')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='A')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D')) return true;
	else return false;			
}
bool checkt(){
	if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D')) return true;
	else return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
	}
	else cout<<"0";
	int shur=shu(sr),shux=shu(sx);
//	cout<<shur<<" "<<shux<<"\n";
	if(cr==cx&&shur==shux){
		cout<<"1";
	}
	else cout<<"0";
	if(cr==cx&&shur==shux&&check()){
		cout<<"1";
	}
	else cout<<"0";
	if(cr==cx&&shur==shux&&checkt()){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
//Trick||Treat!
//-g3
//02 01A 03 01A
//02 02B 02 01A
//02 01C 02 01D
//02 01C 02 01A
//02 01A 02 01B

//8:58
