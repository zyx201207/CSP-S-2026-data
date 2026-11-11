#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string aa,bb;
	cin>>a>>aa>>b>>bb;
	if(a==b){
		if(aa[0]==bb[0]&&aa[1]==bb[1]){
			if((aa[2]=='A'||aa[2]=='B'||aa[2]=='C')&(bb[2]=='A'||bb[2]=='B'||bb[2]=='C')&1){
				if((aa[2]=='A'&&bb[2]=='B')||(aa[2]=='B'&&bb[2]=='A')||(aa[2]=='B'&&bb[2]=='C')||(aa[2]=='C'&&bb[2]=='B')||(aa[2]=='D'&&bb[2]=='F')||(aa[2]=='F'&&bb[2]=='D')){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
} 
