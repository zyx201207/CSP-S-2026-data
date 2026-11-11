#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2)cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	int i=0,f=1,p=max(s1.size(),s3.size());
	while(i<p-1){
		if(s1[i]!=s3[i]){
			f=0;cout<<0<<0<<0;return 0;
		}
		i++;
	}
	if(f==1)cout<<1;
	if('A'<=s1[s1.size()-1] && s1[s1.size()-1]<='C' && 'A'<=s3[s3.size()-1] && s3[s3.size()-1]<='C'){cout<<1;}
	else if('D'<=s1[s1.size()-1] && s1[s1.size()-1]<='F' && 'D'<=s3[s3.size()-1] && s3[s3.size()-1]<='F'){cout<<1;}
	else{cout<<0<<0;return 0;}
	if(s1[s1.size()-1]=='A' && s3[s3.size()-1]=='B')cout<<1;
	else if(s1[s1.size()-1]=='B' && s3[s3.size()-1]=='A')cout<<1;
	else if(s1[s1.size()-1]=='B' && s3[s3.size()-1]=='C')cout<<1;
	else if(s1[s1.size()-1]=='C' && s3[s3.size()-1]=='B')cout<<1;
	else if(s1[s1.size()-1]=='D' && s3[s3.size()-1]=='F')cout<<1;
	else if(s1[s1.size()-1]=='F' && s3[s3.size()-1]=='D')cout<<1;
	else cout<<0;
	return 0;
} 
