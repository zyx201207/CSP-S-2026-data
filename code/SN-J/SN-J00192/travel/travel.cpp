#include<bits/stdc++.h>
using namespace std;
string c2,c4;
int c1,c3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3&&c1!=1&&c1!=16){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(c2[2]=='A'){
		if(c4[2]=='B'){
			cout<<"11";
			return 0;
		}
		if(c4[2]=='C'){
			cout<<"10";
			return 0;
		}
		if(c4[2]=='D'||c4[2]=='F'){
			cout<<"00";
			return 0;
		}
	}
	if(c2[2]=='B'){
		if(c4[2]=='A'){
			cout<<"11";
			return 0;
		}
		if(c4[2]=='C'){
			cout<<"11";
			return 0;
		}
		if(c4[2]=='D'||c4[2]=='F'){
			cout<<"00";
			return 0;
		}
	}
	if(c2[2]=='C'){
		if(c4[2]=='A'){
			cout<<"10";
			return 0;
		}
		if(c4[2]=='B'){
			cout<<"11";
			return 0;
		}
		if(c4[2]=='D'||c4[2]=='F'){
			cout<<"00";
			return 0;
		}
	}
	if(c2[2]=='D'){
		if(c4[2]=='A'||c4[2]=='B'||c4[2]=='C'){
			cout<<"00";
			return 0;
		}
		if(c4[2]=='F'){
			cout<<"11";
			return 0;
		}
	}
	if(c2[2]=='F'){
		if(c4[2]=='A'||c4[2]=='B'||c4[2]=='C'){
			cout<<"00";
			return 0;
		}
		if(c4[2]=='D'){
			cout<<"11";
			return 0;
		}
	}
	return 0;
} 
