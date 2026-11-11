#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if(s1[0]==s1[0]&&s1[1]==s2[1]){
		    cout<<'1';
		    if('A'<=s1[2]<='C'&&'A'<=s2[2]<='C'&&'D'<=s1[2]<='F'&&'D'<=s2[2]<='F'){
		    	cout<<'1';
		    	if(s1[2]+1==s2[2]&&s1[2]!='C'||s2[2]+1==s1[2]&&s2[2]!='C'){
		    		cout<<'1';
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
	    }else{
		    cout<<"000";
	    }
	}else{
		cout<<"0000";
	}
	return 0;
}

