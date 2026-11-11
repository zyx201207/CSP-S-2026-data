#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int q1,q2,q3,q4; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		q1=1;
	}
	else{
		
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		q2=1;
		if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')){
			q3=1;
			if(abs(s1[2]-s2[2])==1){
				q4=1;
			}
		}
		
	}
	cout<<q1<<q2<<q3<<q4;
	
} 
