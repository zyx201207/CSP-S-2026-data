#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){
		cout<<"0000";
		return 0;
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		int num1=10*(s1[0] - '0')+(s1[1] - '0');
		int num2=10*(s2[0] - '0')+(s2[1] - '0');
		if(num1!=num2){
			cout<<"000";
			return 0;
		}
		else{
			cout<<1;
			int x = s1[2]-'A';
			int y = s2[2]-'A';
			if( (x<=2 && y>=3) || (x>=3 && y<=2) ){
				cout<<"00";
				return 0;
			}
			else{
				cout<<1;
				if(abs(x-y)==1){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
		}
	}
    return 0;
}
