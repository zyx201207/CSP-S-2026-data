#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		char a,b;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				cout<<"1000";
				return 0;
			}
		}
		a=s1[2],b=s2[2];
		if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
			if(abs(int(a-b))==1){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1110";
				return 0;
			}
		}else{
			cout<<"1100";
			return 0;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
