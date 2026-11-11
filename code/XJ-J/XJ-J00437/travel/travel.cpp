#include <bits/stdc++.h>
using namespace std ;
long long int x,p,c,l,c1,c2;
bool vi[30]={0};
string s1,s2;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int la=s1.size(),lb=s2.size();
	if(c1!=c2){
	cout<<"0000";
	return 0;}
	if(s1[0]==s2[0])
	 cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}if(s1[1]==s2[1]&&s1[0]==s2[0])
	 cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	
	if(s1[la-1]=='A'&&s2[lb-1]=='B'||s1[la-1]=='B'&&s2[lb-1]=='A'||s1[la-1]=='A'&&s2[lb-1]=='C'||s1[la-1]=='C'&&s2[lb-1]=='A'||s1[la-1]=='B'&&s2[lb-1]=='C'||s1[la-1]=='C'&&s2[lb-1]=='B'||s1[la-1]=='D'&&s2[lb-1]=='F'||s1[la-1]=='F'&&s2[lb-1]=='D')
	cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if(s1[la-1]=='A'&&s2[lb-1]=='B'||s1[la-1]=='B'&&s2[lb-1]=='A'||s1[la-1]=='B'&&s2[lb-1]=='C'||s1[la-1]=='C'&&s2[lb-1]=='B'||s1[la-1]=='D'&&s2[lb-1]=='F'||s1[la-1]=='F'&&s2[lb-1]=='D')
	cout<<'1';
	else{
		cout<<'0';
		return 0;
	}//*/
}