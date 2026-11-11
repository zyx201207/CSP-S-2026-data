#include<iostream> 
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
bool cp(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C')
		  return true;
		else return 0;
	}
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F')
		  return true;
		else return 0;
	}
}
bool np(char a,char b){
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F')
		  return true;
		else return 0;
	}
	if(a=='A'){
		if(b=='B')
		   return true;
		else return 0;
	}
	if(a=='B'){
		if(b=='A'||b=='C')
		  return true;
		else return 0;
	}
	if(a=='C'){
		if(b=='B')
		  return true;
		else return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ac,az,bc,bz;
	cin>>ac>>az>>bc>>bz;
	if(ac==bc){
		cout<<"1";
		int ak,bk;
		ak=(az[0]-48)*10+(az[1]-48);
		bk=(bz[0]-48)*10+(bz[1]-48);
	//	cout<<ak<<endl<<bk;
		if(ak==bk){
			cout<<"1";
			char al=az[2],bl=bz[2];
			if(cp(al,bl)){
				cout<<"1";
				if(np(al,bl))
					cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
