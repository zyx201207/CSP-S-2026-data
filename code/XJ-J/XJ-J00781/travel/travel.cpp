#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1,s2;
	int d1,d2;
	int c1,c2;
	cin>>c1>>d1>>s1>>c2>>d2>>s2;
	if(c1==1||c1==16||c2==1||c2==16){
		cout<<"0000";
	}else{
		if(c1==c2){
			cout<<"1";
			if(d1==d2){
				cout<<"1";
				if(s1=='A'||s1=='B'||s1=='C'&&s2=='A'||s2=='B'||s2=='C'){
					cout<<"1";
					if(s1+1==s2||s1-1==s2){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else if(s1=='E'||s1=='F'&&s2=='E'||s2=='F'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else{
				cout<<"000";
			}
		}else{
			cout<<"0000";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}