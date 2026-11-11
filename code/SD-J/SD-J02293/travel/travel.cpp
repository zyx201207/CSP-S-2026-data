#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int t1=s1[2]-'0';
	int t2=s2[2]-'0';
	if(c1==c2){
		if(s1[1]==s2[1]){
			if(abs(t1-t2)==1){
				if(t1<=19&&t2>=20){
					cout<<"1100";
					return 0;
				}
				else{
					cout<<"1111";
					return 0;
				}
			}
			else{
				cout<<"1110";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
