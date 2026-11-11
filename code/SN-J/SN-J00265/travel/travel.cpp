#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string q;
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			int z = s1[2]-'A';
		    int x = s2[2]-'A';
		    if(z<3&&x<3||z>2&&x>2){
			    if(z-1==x||z+1==x){
		    		q = "1111";
			   	    cout << q;
				}else{
					q = "1110";
					cout << q;
				}
		    }else{
		    	q = "1100";
		    	cout << q;
			}
		}else{
			q = "1000";
			cout << q;
		}
	}else{
		q = "0000";
		cout << q;
	}
	return 0;
} 
