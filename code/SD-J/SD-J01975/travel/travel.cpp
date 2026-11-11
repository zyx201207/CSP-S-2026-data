#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=1,f2=0,f3=0,f4=0;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			f1=0;
			break;
		}
	}
	if(f1==1){
		f2=1;
		for(int i=0;i<s1.size()-1;i++){
			if(s1[i]!=s2[i]){
				f2=0;
				break;
			}	
		}
		if(f2==1){
			int a=0,b=0;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
				a++;
			else
				b++;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				a++;
			else
				b++;
			if(a==2||b==2)
				f3=1;
			if(f3==1){
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F')
					f4=1;
				if(s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D')
					f4=1;				
			}				
		}	
	}
	cout<<f1<<f2<<f3<<f4;	
	return 0;
}

