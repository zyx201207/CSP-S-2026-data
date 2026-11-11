#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+(ch-'0');ch=getchar();}
	return ret;
}
string s1,s2,s3,s4,s5;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){s5+="1";
		if(s2[0]==s4[0]&&s2[1]==s4[1]){s5+="1";
		    if((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='F'||s4[2]=='D')){s5+="11";}
			else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')){s5+="1";
				if((s2[2]=='A'||s2[2]=='B')&&(s4[2]=='A'||s4[2]=='B')) s5+="1";
				else if((s2[2]=='B'||s2[2]=='C')&&(s4[2]=='C'||s4[2]=='B')) s5+="1";
				else s5+="0";
			}else s5="1100";	
		}else s5="1000";
	}else s5="0000";
	cout<<s5;
	return 0;
}
