#include<bits/stdc++.h>
//#define int long long
using namespace std;
string cc1,cc2,ss1,ss2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cc1>>ss1>>cc2>>ss2;
	if(cc1!=cc2){
		cout<<"0000";
	}else{
		cout<<"1";
		if(ss1[0]!=ss2[0]||ss1[1]!=ss2[1]){
			cout<<"000";
		}else{
			cout<<"1";
			if(ss2[2]>='D'&&ss1[2]>='D'){
				cout<<"11";
			}else{
				if(ss2[2]<='C'&&ss1[2]<='C'){
					cout<<"1";
					if(ss2[2]<='B'&&ss1[2]<='B'||ss2[2]>='B'&&ss1[2]>='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}
		}
	}
	 
	
	return 0;
}
