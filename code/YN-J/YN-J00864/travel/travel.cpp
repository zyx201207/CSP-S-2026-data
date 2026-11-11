#include<bits/stdc++.h>
using namespace std;
pair<string,string>c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1.first>>c1.second>>c2.first>>c2.second;
	if(c1.first==c2.first){
		cout<<"1";
		if(c1.second[0]==c2.second[0]&&c1.second[1]==c2.second[1]){
			cout<<"1";
			if((c1.second[2]=='A'||c1.second[2]=='B'||c1.second[2]=='C')&&(c2.second[2]=='A'||c2.second[2]=='B'||c2.second[2]=='C')){
				cout<<"1";
				if(abs(int(c1.second[2])-int(c2.second[2]))==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if((c1.second[2]=='D'||c1.second[2]=='F')&&(c2.second[2]=='D'||c2.second[2]=='F')){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
