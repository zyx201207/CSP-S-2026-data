#include<bits/stdc++.h>
using namespace std;
string s,s1,ss,ss1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>ss>>ss1;
	if(s.size()!=ss.size()){
		cout<<'0';
	}
	else{
		bool f=1;
		for(int i=0;i<s.size();i++){
			if(s[i]!=ss[i]){
				f=0;
				break;
			}
		}
		cout<<f;
		if(f==0){
			cout<<"000";
			return 0;
		}
	}
	if(s1[0]==ss1[0]&&ss1[1]==s1[1]){
		cout<<'1';
	    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(ss1[2]=='A'||ss1[2]=='B'||ss1[2]=='C')){
	        cout<<'1';
	        if(s1[2]=='A'&&ss1[2]=='B')
	            cout<<'1';
	        else if(s1[2]=='B'&&(ss1[2]=='A'||ss1[2]=='C'))
	            cout<<'1';
	        else if(s1[2]=='C'&&ss1[2]=='B')
	            cout<<'1';
	        else 
	            cout<<'0';
	    }
	    else if((s1[2]=='D'||s1[2]=='F')&&(ss1[2]=='D'||ss1[2]=='F'))
	        cout<<"11";
	    else{
	        cout<<"00";
	        return 0;
	    }
	}
	else{
	    cout<<"000";
	    return 0;
	}
	
	return 0;
}
