#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int l=s1.size();
	int n=0;
	if(c1==c2){
		s3[0]='1';
	}
	else{
		s3[0]='0';
	}
	for(long long int i=1;i<=l;i++){
		int a,b;
		a=(a+s1[1])*10+s1[2];
		a=(a+s2[1])*10+s2[2];		
		if(s1[l]!=s2[l]&&a==b){
			s3[1]='1';
		}
		else{
			s3[1]='0';	
		}
		if((s1[i-1]=='A'&&s2[i-1]=='B')||(s1[i-1]=='A'&&s2[i-1]=='C')||(s1[i-1]=='B'&&s2[i-1]=='C')){
			s3[2]='1';
		}
		else{
			s3[2]='0';
		}
		if((s1[i-1]=='A'&&s2[i-1]=='B')||(s1[i-1]=='B'&&s2[i-1]=='C')||(s1[i-1]=='D'&&s2[i-1]=='E')){
			s3[3]='1';
		}
		else{
			s3[3]='0';
		}		
	}
	for(long long int i=0;i<=3;i++){
		cout<<s3[i];
	}
	return 0;	
}