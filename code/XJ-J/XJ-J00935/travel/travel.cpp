#include<bits/stdc++.h>
using namespace std;
char n=0,m=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[2]){
			cout<<"1";
			n=s1[2];
			m=s2[2];
			if((n=='A'||n=='B'||n=='C')&&(m=='A'||m=='B'||m=='C')||((n=='D'||n=='F')&&m=='D'||m=='F')){
				cout<<"1";
				if(n-m==1||m-n==1){
					cout<<"0";
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
	fclose(stdin);
	fclose(stdout);	
	return 0;
}