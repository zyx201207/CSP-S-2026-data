#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]){
		cout<<1;
		
}else{
	cout<<0;
}
		if(c1==c2&&s1[1]==s2[1]){
			cout<<"1";
		}else{
			cout<<"0";
			
	}
		if(c1==c2&&s1[2]==s2[2]&&s1[1]=='A'&&s2[1]=='B'||s2[1]=='C'||s2[1]=='D'||s2[1]=='A'){
			cout<<"1";
		}else{
			cout<<"0";
		
		}
			if(c1==c2&&s1[1]==s2[1]&&s1[1]=='B'&&s2[1]=='B'||s2[1]=='C'||s2[1]=='D'||s2[1]=='A'){
			cout<<"1";
		}else{
			cout<<"0";
			return 0;
		}
			if(s1[2]=='C'&&s2[2]=='B'||s2[2]=='C'||s2[2]=='D'||s2[2]=='A'){
			cout<<"1";
		}else{
			cout<<"0";
		}
			if(s1[2]=='D'&&s2[2]=='B'||s2[2]=='C'||s2[2]=='D'||s2[2]=='A'){
			cout<<"1";
		}else{
			cout<<"0";
		}
			if(s1[2]=='E'&&s2[2]=='E'||s2[2]=='F'||s2[2]=='G'){
			cout<<"1";
		}else{
			cout<<"0";
		}
			if(s1[2]=='F'&&s2[2]=='E'||s2[2]=='F'||s2[2]=='G'){
			cout<<"1";
		}else{
			cout<<"0";
		}
			if(s1[2]=='G'&&s2[2]=='E'||s2[2]=='F'||s2[2]=='G'){
			cout<<"1";
		}else{
			cout<<"0";
	
		}
if(c1==c2&&s1==s2){
	cout<<1111;
}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

