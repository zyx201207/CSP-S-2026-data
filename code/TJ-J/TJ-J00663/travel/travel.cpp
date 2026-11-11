#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans;
	int a=0,b=0,c=0,d=0;
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i=0;i<2;++i){
		if(c1[i]==c2[i]){
			a++;
			if(a==2){
				cout << 1;
				for(int j=0;j<3;++j){
					if(s1[j]==s2[j]){
						b++;
						if(b==2){
							cout << 1;
							if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
								cout << 11;
							}
							else if(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
								cout << 11;
							}
							else if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
								cout << 10;
							}	
							else if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'){
								cout << 11;
							}
							else{
								cout << 00;
							}
						}	
					}
				}		
			}
		}
	}
	if(a!=2){
		cout << 0000;
	}
	if(b!=2){
		cout << 000;
	}
	return 0;
}
