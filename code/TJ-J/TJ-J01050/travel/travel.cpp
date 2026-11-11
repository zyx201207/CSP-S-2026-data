#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[5],s2[5];
	cin >> c1;
	for(int i=0;i<4;i++)cin >> s1[i];
	cin >> c2;
	for(int i=0;i<4;i++)cin >> s2[i];
	if(c1!=c2){
		cout << "0000";
	}
	if((s1[1]!=s2[1])&& (c1==c2)){
		cout << "0100";
	}
		if(s1[1]==s2[1]){
			cout << "1";
				if(s1[2]-s2[2]<=1){
					cout << "1";
	
				}
				else{
					cout << "0000";
				}
			}	
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
