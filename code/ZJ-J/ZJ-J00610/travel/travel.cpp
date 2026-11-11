#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a1,a2,a3,a4,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a1=1;
	}
	if(a1){
		string ss1=""+s1[0]+s1[1],ss2=""+s2[0]+s2[1];
		if(ss1==ss2){
			a2=1;
		}
	}
	if(a2&&a1){
		char p1=s1[2],p2=s2[2];
		if( ((p1>='A'&&p1<='C')&&(p2>='A'&&p2<='C') ) || ((p1=='D'&&p2=='F')||(p1=='F'&&p2=='D')) )
			a3=1;
		if( ((p1=='D'&&p2=='F')||(p1=='F'&&p2=='D'))){
			bb=1;
		}
	}
	if(a3&&a2&&a1){
		char p1=s1[2],p2=s2[2];
		if(bb){
			a4=1;
		}
		else{
			if(abs(p1-p2)==1){
				a4=1;
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
