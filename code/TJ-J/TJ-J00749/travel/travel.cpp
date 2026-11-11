#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//∑¢»»open 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a = 0,b = 0,c = 0,d = 0;
	char s[11];
	for(int i = 1;i<=10;++i){
		cin>>s[i];
	} 
	if(s[1] == s[6]&&s[2] == s[7]){
		a = 1;
	}
	if(s[3] == s[8]&&s[4] == s[9]&&a == 1){
		b = 1;
	}
	if((((s[5] == 'A'||s[5] == 'B'||s[5] == 'C')&&(s[10] == 'A'||s[10] == 'B'||s[10] == 'C'))||((s[5] == 'D'||s[5] == 'F')&&(s[10] == 'D'||s[10] == 'F')))&&b == 1&&a == 1){
		c = 1;
	}
	if(c == 0){
		d = 0;
	}else{
		d = 1;
		if(s[5]=='B'||s[10] == 'B'){
			d = 1;
		}else{
			d = 0;
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
