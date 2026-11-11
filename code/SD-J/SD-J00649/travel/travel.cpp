#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1[0]==s1[0]&&c1[1]==s1[1]){//同一节车厢 
		cout<<1;
		if(c2[0]==s2[0]&&c2[1]==s2[1]){//同一排 
			cout<<1;
			if((c2[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&c2[2]=='F')){//同一侧 
				cout<<1<<1;
			}
			else if(c2[2]>='A'&&c2[2]<='C'&&s2[2]<='C'&&s2[2]>='A'){//相邻 
				cout<<1;
				if((c2[2]=='A'&&s2[2]=='B')||(c2[2]=='B'&&s2[2]=='C')||(c2[2]=='B'&&s2[2]=='A')||(c2[2]=='C'&&s2[2]=='B')){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}

