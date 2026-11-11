#include<bits/stdc++.h>
#define ll long long
#define IMAX INT_MAX
#define IMIN INT_MIN
using namespace std;
ll c1,c2;
string s1,s2;
struct saet{
	ll car;
	ll line;
	char seet;
}; 
saet r,x;
bool pd(char a,char b){
	if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//---------------------------
	cin>>c1>>s1>>c2>>s2;
	//------------------------
	ll st1,st2;
	st1=(s1[0]-'0')*10+(s1[1]-0);
	st2=(s2[0]-'0')*10+(s2[1]-0);
	//----------------------
	r.car=c1;x.car=c2;
	r.line=st1;x.line=st2;
	r.seet=s1[2];x.seet=s2[2];
	//--------------------
	//车厢一样 
	if(r.car==x.car){
		cout<<1;
	}
	else{
		cout<<0;
	}
	//--------------------------
	//车厢一样，排一样 
	if(r.car==x.car&&x.line==r.line){
		cout<<1;
	}
	else{
		cout<<0;
	}
	//---------------------
	//车厢一样，排一样，在过道 
	if(r.car==x.car&&x.line==r.line&&pd(r.seet,x.seet)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	//---------------------
	//车厢一样，排一样，相邻 
	if(r.car==x.car&&x.line==r.line&&((r.seet=='A'&&x.seet=='B')||(r.seet=='B'&&x.seet=='C')||(r.seet=='D'&&x.seet=='F'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	//---------------------
	
	//continue;
	//break;
	
	fclose(stdin);
	fclose(stdout);
}
