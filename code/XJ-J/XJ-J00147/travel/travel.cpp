#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin.tie(0),cout.tie(0);
	int c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1/10==s2/10){
			if((s1%10=='A'||s1%10=='B'||s1%10=='C')&&(s2%10=='A'||s2%10=='B'||s2%10=='C')){
					cout<<"1110";
			}
			else if(((s1%10=='D'||s1%10=='E')&&(s2%10=='D'||s2%10=='E'))){
				cout<<"1111";
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
