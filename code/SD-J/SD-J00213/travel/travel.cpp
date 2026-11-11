#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
/*####################*/
using lnt=long long;
/*####################*/
string str1,str2,str3,str4; 
/*####################*/
void Solve(void){
	cin>>str1>>str2>>str3>>str4;
	if(str1!=str3){
		cout<<"0000";
		return;
	}else{
		if(str2[0]!=str4[0]||str2[1]!=str4[1]){
			cout<<"1000";
			return;
		}else{
			bool flag1=(str2[2]<='C');
			bool flag2=(str4[2]<='C');
			if(flag1!=flag2){
				cout<<"1100";
				return;
			}else{
				if(flag1==false){
					cout<<"1111";
					return;
				}else{
					if(str2[2]=='B'||str4[2]=='B'){
						cout<<"1111";
						return;
					}else{
						cout<<"1110";
						return;
					}
				}
			}
		}
	}
}
/*####################*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;//cin>>T;
	while(T--) Solve();
	return 0;
}
