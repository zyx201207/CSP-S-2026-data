#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		int n1=0,n2=0;
		for(int i=0;i<2;++i){
			n1=n1*10+(s1[i]-'0');
			n2=n2*10+(s2[i]-'0');
		}
		if(n1!=n2){
			cout<<"000";
			return 0;
		}
		else{
			cout<<1;
			bool flag=false;
			if(!('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C'||
	   		   'D'<=s1[2] && s1[2]<='F' && 'D'<=s2[2] && s2[2]<='F')){
	   			cout<<"00";
	   			return 0;
	   		}
	   		else{
	   			cout<<1;
	   			if(s1[2]=='A' && s2[2]=='B'||s2[2]=='A' && s1[2]=='B'||s1[2]=='B' && s2[2]=='C'||
				   s2[2]=='B' && s1[2]=='C'||s1[2]=='D' && s2[2]=='F'||s2[2]=='D' && s1[2]=='F')cout<<1;
				else cout<<0;
		    }
		} 
		
	}
	return 0;
}