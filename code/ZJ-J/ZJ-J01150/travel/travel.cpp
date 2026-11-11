#include<bits/stdc++.h>
using namespace std;
string ans;
int check(char a,char b){
	if(a<='C'&&b<='C')return 2;
	else if(a>'C'&&b>'C')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1_car,s2_car,s1_seat,s2_seat;
	cin>>s1_car>>s1_seat>>s2_car>>s2_seat;
	if(s1_car==s2_car){
        if(s1_seat[0]==s2_seat[0]&&s1_seat[1]==s2_seat[1]){
        	char p=s1_seat[2],q=s2_seat[2];
        	int t=check(p,q);
        	if(t==2){
        		if((q=='A'&&p=='B')||(q=='B'&&p=='A')||(q=='C'&&p=='B')||(q=='B'&&p=='C'))ans="1111";
        		else ans="1110";
			}else if(t==1){
				ans="1111";
			}else ans="1100";
		}
        else ans="1000";
	}
	else ans="0000";
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}