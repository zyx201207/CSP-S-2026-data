#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int c1,c2;
	char s1,s2;
	cin>>c1>>c2;
	cin>>s1>>s2;
	if((s1=='A'||s1=='B'||s1=='C')&&(s2=='A'||s2=='B'||s2=='C')){
		if((s1=='A'&&s2=='B')||(s2=='A'&&s1=='B')||(s1=='B'&&s2=='C')||(s2=='B'&&s1=='C')){
			cout<<"1111";	
		}
		else{
			cout<<"1110";
		}
	}
	if((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')){
		cout<<"1111";
	}

	return 0;
}

