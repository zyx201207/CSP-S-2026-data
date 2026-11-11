#include<bits/stdc++.h>
using namespace std;
bool c,s,p,l;//车厢，排，过道，是否相邻 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],c2[3],s1[3],s2[3];
	cin>>c1>>s1>>c2>>s2;	
	if((c1[0]+c1[1])-'0'==(c2[0]+c2[1])-'0'){
		c=true;
	} 
	if(c==false){
		s=false;
		p=false;
		l=false;
		cout<<c<<s<<p<<l<<endl;
		return 0;
	}
	if((s1[0]+s1[1])-'0'==(s2[0]+s2[1])-'0'){
		s=true;
	}
	if(s1[2]=='C'||s1[2]=='B'||s1[2]=='A'){
		if(s2[2]!=s1[2]){
			if(s2[2]=='C'||s2[2]=='B'||s1[2]=='A'){
				if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')){
					p=true;
				}	
			}
		}
	}
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]!=s1[2]){
			if(s2[2]=='D'||s2[2]=='F'){
				p=true;
			}
		}
	}
	if(c==true&&s==true&&p==true){
		l=true;
	}
	cout<<c<<s<<p<<l<<endl;
	return 0;
}
