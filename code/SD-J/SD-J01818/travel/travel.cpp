#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve(void){
	string a_1,b_1;
	string a_2,b_2;
	cin>>a_1>>a_2>>b_1>>b_2;
	int x=(a_2[0]-'0')*10+a_2[1]-'0';
	int y=(b_2[0]-'0')*10+a_2[1]-'0';
	if(a_1==b_1){
		cout<<"1";
		if(x==y){
			cout<<"1";
			if(((a_2[2]<='C'&&b_2[2]<='C')||('D'<=a_2[2]&&'D'<='b_2'))){
				cout<<"1";
				if(a_2[2]+1==b_2[2]||a_2[2]==b_2[2]+1||a_2[2]=='D'&&b_2[2]=='F'||b_2[2]=='D'&&a_2[2]=='F'){
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
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;//cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
