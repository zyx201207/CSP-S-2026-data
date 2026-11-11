#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <stack>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1){
		cout<<1;
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			cout<<1;
			char p=s2[2],q=c2[2];
			
			if((q!=p)&&(p=='D'||p=='F')&&(q=='D'&&q=='F')||(q!=p)&&(q=='A'||q=='B'||q=='C')&&(p=='A'||p=='B'||p=='C')){
				cout<<1;
				if(q>p)swap(q,p);
				if(q=='A'&&p=='B'||q=='B'&&p=='C'||q=='D'&&p=='F')cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
//start 0h
//end 0.4h
