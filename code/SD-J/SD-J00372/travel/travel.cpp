#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ra,rb,xa,xb;
	cin>>ra>>rb>>xa>>xb;
	if(ra==xa){
		cout<<"1";
		if(rb[0]==xb[0]&&rb[1]==xb[1]){
			cout<<"1";
			if((int(rb[2])<=67&&int(xb[2])<=67)||(int(rb[2])>67&&int(xb[2])>67)){
				cout<<"1";
				if(int(rb[2])-int(xb[2])==1||int(rb[2])-int(xb[2])==-1){
					cout<<"1";
				}else{
					cout<<"0";
				}
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
