#include<bits/stdc++.h>
using namespace std;
char c1[50],s1[50],c2[50],s2[50];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char num[0],[1],[2],[3];
	for(int i=1;i<=2;i++){
		cin>>c1[i];
	}
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c2[i];
	}
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(s1[2]=='A'){
		s1[2]=='1';
	}
	else if(s1[2]=='B'){
		s1[2]=='2';
	}
	else if(s1[3]=='C'){
		s1[3]=='3';
	}
	else if(s1[4]=='D'){
		s1[4]=='5';
	}
	else if(s1[5]=='F'){
		s1[5]=='6';
	}
	if(s2[2]=='A'){
		s2[2]=='1';
	}
	else if(s2[2]=='B'){
		s2[2]=='2';
	}
	else if(s2[3]=='C'){
		s2[3]=='3';
	}
	else if(s2[4]=='D'){
		s2[4]=='5';
	}
	else if(s2[5]=='F'){
		s2[5]=='6';
	}
	if(c1[50]!=c2[50]){
		cout<<"0000";
	}
	else if(c1[50]==c2[50]){
		num[0]='1';
		if(s1[50]==s2[50]){
			num[1]='1';
			if(s1[1]==s2[2]&&s1[2]==s2[3]&&s1[1]==s2[3]&&s1[5]==s2[6]){
				num[2]=='1';
				if(s1[1]==s2[2],s1[2]==s2[3],s1[5]==s2[6]){
					num[3]='1';
				}
			}
		}
	}
	cout<<num[0]<<num[1]<<num[2]<<num[3];
	return 0;
}
