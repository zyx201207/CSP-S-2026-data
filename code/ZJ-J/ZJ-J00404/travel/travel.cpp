#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		int cc=0;
		for(int i=0;i<2;i++){
			if(b[i]==d[i]){
				cc++;
			}
		}
		if(cc==2){
			cout<<"1";
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
				cout<<"1";
				if(b[2]=='B'||d[2]=='B'){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				if((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D'||d[2]=='C')){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}