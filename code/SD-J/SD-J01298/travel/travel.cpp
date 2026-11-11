#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,s3,s4;
	cin>>c1>>s1>>c2>>s2;
	char s5,s6;
	s5=s1[s1.length()-1];
	s6=s2[s2.length()-1];
	if (c1==c2){
		cout<<"1";
		for (int i=0;i<s1.length()-1;i++){
		    s3+=s1[i];
	    }
	    for (int i=0;i<s2.length()-1;i++){
		    s4+=s2[i];
	    } 
	    if (s3==s4){
		    cout<<"1";
		    if ((s5<='C'&&s6<='C')||(s5>'C'&&s6>'C')){
		    	cout<<"1";
		    	if ((s5=='A'&&s6=='B')||(s5=='B'&&s6=='A')||(s5=='C'&&s6=='B')||(s5=='B'&&s6=='C')||(s5=='D'&&s6=='F')||(s5=='F'&&s6=='D')){
		    		cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
				return 0;
			}
	    }
	    else{
		    cout<<"000";
		    return 0;
	    }
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0; 
} 
