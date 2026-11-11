#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q1=0,q2=0,q3=0,q4=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		q1=1;
	}
	if(q1==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		q2=1;
	}
	if(q2==1&&s1[2]=='D'&&s2[2]=='F'||q2==1&&s1[2]=='F'&&s2[2]=='D'){
		q3=1; 
	}
	else if(q2==1){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				q3=1;
			}
		}
	}
	if(q3==1){
		if(s1[2]!='D'&&s2[2]!='F'||s1[2]!='F'&&s2[2]!='D'){
			if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
				q4=1;
			}
		}
		else{
			q4=1;
		}	
	}
	cout<<q1<<q2<<q3<<q4;
	return 0;
}
