#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=(c1[0]-'0')*10,a1=c1[1]-'0';
	int b=(c2[0]-'0')*10,b1=c2[1]-'0';
	if(c1==c2&&(a+a1!=1&&a+a1!=16&&b+b1!=1&&b+b1!=16)){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<1;
				if(s1[2]!=s2[2]){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<1;
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
				cout<<0;
			}
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
