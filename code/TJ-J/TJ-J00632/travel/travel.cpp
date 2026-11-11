#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,se,sy;
	string s1,s2;
	bool boc=0,bos=0,bocs=0,bol=0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		boc=1;
	}
	se=(s2[0]-'0')*10+(s2[1]-'0');
	sy=(s1[0]-'0')*10+(s1[1]-'0');
	if(sy==se&&!boc){
		bos=1;
	}
	if(!boc&&bos){
		bocs=1;
	}
	if(bocs){
		if(s1[2]-1==s2[2]&&s1[2]!='D'){
			bol=1;
		}
		else if(s2[2]-1==s1[2]&&s2[2]!='D'){
			bol=1;
		}
	}
	if(s2[2]>s1[2]&&s2[2]=='D'){
		bocs=0;
		bos=0;
	}
	if(s1[2]>s2[2]&&s1[2]=='D'){
		bocs=0;
		bos=0;
	}
	if(boc){
		cout << 0;
	}
	else{
		cout << 1;
	}
	if(bos){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if(bocs){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(bol){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
