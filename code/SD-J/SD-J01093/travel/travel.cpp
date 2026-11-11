#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			char aa=s1[2];
			char bb=s2[2];
			if('A'<=aa && aa<='C' && 'A'<=s2[2] && s2[2]<='C'){
				cout<<"1";
				if(int(aa-bb)==1 || int(bb-aa)==1){
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
