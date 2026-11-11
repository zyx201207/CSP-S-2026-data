#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		int pai1=s1[0]*10+s1[1],pai2=s2[0]*10+s2[1];
		if(pai1!=pai2)cout<<1000;
		else{
			char hang1=s1[2],hang2=s2[2];
			if((hang1=='F' || hang1=='D')&&(hang2=='C' || hang2=='B' || hang2=='A'))cout<<1100;
			else if((hang2=='F' || hang2=='D')&&(hang1=='C' || hang1=='B' || hang1=='A'))cout<<1100;
			else{
				if((hang1=='C' && hang2=='A')||(hang1=='A' && hang2=='C'))cout<<1110;
				else cout<<1111;
			}
		}
	}
}
