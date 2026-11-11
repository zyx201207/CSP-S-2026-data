#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	string n;
	
		cin>>c1;
		cin>>c2;
		cin>>s1;
		cin>>s2;
	
	for(int i;i>=0;i<=3){
		if(c1==s1){
		   n+='1';
		   cout<<n;
		   n={};
		   break;
		}else{
		n+='0';
		cout<<n<<n<<n<<n;
	    return 0;
		}
		
	}
	for(int i;i>=0;i<=3){
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			n+='1';
		   	cout<<n;
		   	n={};
		   	break;
		}else{
		n+='0';
		cout<<n<<n<<n;
	    return 0;
		}
	}
	for(int i;i>=0;i<=3){
		if(((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((c2[2]=='D'||c2[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
		    n+='1';
		   	cout<<n;
		   	n={};
		   	break;	
		}else{
		n+='0';
	    cout<<n<<n;
	    return 0;
		}
	}
	for(int i;i>=0;i<=3){
		if((c2[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s2[2]=='B'&&(c2[2]=='A'||c2[2]=='C'))||(s2[2]=='C'&&c2[2]=='B')||(s2[2]=='A'&&c2[2]=='B')||(c2[2]=='C'&&s2[2]=='B')||(c2[2]=='A'&&s2[2]=='B')||(c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'&&s2[2]=='D')){
		    n+='1';
		   	cout<<n;
		   	n={};
		   	break;
		}else{
		n+='0';
	    cout<<n;
	    return 0;
		}	
	}
	return 0;
} 
