#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int s[4]={};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>c;
	cin>>b;
	cin>>d;
	if(a==b){
		s[0]=1;
		if(c[0]==d[0]&&c[1]==d[1]){
			s[1]=1;
			if((c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D')||((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))){
				s[2]=1;
				if(c[2]-d[2]==1||d[2]-c[2]==1){
					s[3]=1;
				}
				else{
					s[3]=0;
				}
			}
			else{
				s[2]=0;
				s[3]=0;
			}
		}
		else{
			s[1]=0;
			s[2]=0;
			s[3]=0;
		}
	}	
	else{
		s[0]=0;
		s[1]=0;
		s[2]=0;
		s[3]=0;
	}
	for(int i=0;i<4;i++){
		cout<<s[i];
	}
	return 0;
}