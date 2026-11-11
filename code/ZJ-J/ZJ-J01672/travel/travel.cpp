#include<bits/stdc++.h>
#define ll long lnog
using namespace std;
string c1,c2,c3,c4;
int ff;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(c2[i]!=c4[i]){
			cout<<"000";
			return 0;
		}
	}
	ff=0;
	cout<<1;
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
		if(c4[2]=='A'||c4[2]=='B'||c4[2]=='C'){
			cout<<1;
			ff=1;
		}
	}
	else if(c2[2]=='D'||c2[2]=='F'){
		if(c4[2]=='D'||c4[2]=='F'){
			cout<<1;
			ff=1;
		}
	}
	if(ff==0){
		cout<<"00";
		return 0;
	}
	if(abs(c2[2]-c4[2])==1||c2[2]=='D'&&c4[2]=='F'||c2[2]=='F'&&c4[2]=='D')cout<<1;
	else cout<<"0";
	return 0;
}