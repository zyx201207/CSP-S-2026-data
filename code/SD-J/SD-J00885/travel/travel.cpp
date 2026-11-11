#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int gg(string s1,string s2){
	int jj1 = 0,jj2 = 0;
	if(s1[2] == 'C' || s1[2] == 'B' || s1[2] == 'A'){
		jj1 = 1;
	}
	if(s2[2] == 'C' || s2[2] == 'B' || s2[2] == 'A'){
		jj2 = 1;
	}
	if(jj1 == jj2){
		return 1;
	}
	return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout<<1;
			if(gg(s1,s2) == 1){
				cout<<1;
				if(abs(s1[2]-s2[2]) == 1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
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
