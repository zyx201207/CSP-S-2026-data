#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
				cout<<1;
				if(a-b==1||b-a==1)cout<<1;
				else cout<<0;
			}else{
				cout<<0;
			}
			if(a=='D'||a=='F'&&b=='D'||b=='F'){
				cout<<1<<1;
			}
			if(a>='A'&&a<='C'&&b>='D'&&b<='F')cout<<00;
			if(b>='A'&&b<='C'&&a>='D'&&a<='F')cout<<00;
		}else{
			cout<<0<<0<<0;
		}
		
	}else{
		cout<<0<<0<<0<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
