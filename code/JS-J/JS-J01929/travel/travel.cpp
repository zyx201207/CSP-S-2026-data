#include<bits/stdc++.h>
using namespace std;
int n,m;
char a,b,c,d,e,f;
int s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>b>>c>>m>>d>>e>>f;
	s1=(a-'0')*10+(b-'0');
	s2=(d-'0')*10+(e-'0');
	if(m==n){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			char s3=min(c,f);
			char s4=max(c,f);
			if((s3=='A'&&(s4=='B'||s4=='C'))||(s3=='D'&&s4=='F')){
				cout<<"1";
				if(s4-s3==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
