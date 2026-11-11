#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a,b,c,d;
	if(c1==c2&&c1!=1&&c1!=16&&c2!=1&&c2!=16){
//		a=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
//			b=1;
			char a1=s1[2],b1=s2[2];
			if(a1='A'&&b1=='B'||a1=='B'&&b1=='A'||a1=='A'&&b1=='C'||a1=='C'&&b1=='A'||a1=='B'&&b1=='C'||a1=='C'&&b1=='B'||a1=='D'&&b1=='F'||a1=='F'&&b1=='D')
			{
				int x=s1[2]-'0',y=s2[2]-'0';
				if(abs(x-y)!=1||s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
					cout<<"1110";
					return 0;
				}
				else{
					cout<<"1111";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
		
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
