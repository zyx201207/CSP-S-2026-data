#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";
		char ch1=s1[0],ch2=s2[0],ch3=s1[1],ch4=s2[1];
		if(ch1!=ch2||ch3!=ch4)cout<<"000";
		else{
			cout<<"1";
			char l=s1[2],r=s2[2];
			if(l>r)swap(l,r);
			if((l=='A'||l=='B'||l=='C')&&(r=='D'||r=='F'))cout<<"00";
			else{
				cout<<"1";
				if(r-l==1||(l=='D'&&r=='F'))cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
} 
