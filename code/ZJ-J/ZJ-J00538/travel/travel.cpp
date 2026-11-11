#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3){
		cout<<"0000";
	}
	else{
		if(c2[0]*10+c2[1]!=c4[0]*10+c4[1]){
			cout<<"1000";
		}
		else{
			if((c2[2]=='D'&&c4[2]!='F')||(c2[2]=='F'&&c4[2]!='D')||(c4[2]=='D'&&c2[2]!='F')||(c4[2]=='F'&&c2[2]!='D')){
				cout<<"1100";
			}
			else{
				if(c2[2]=='D'||c2[2]=='F') cout<<"1111";
				else if(abs(int(c2[2])-int(c4[2]))==1) cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}