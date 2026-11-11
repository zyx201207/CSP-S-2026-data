#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a,b,c,d;
	char s1[4],s2[4];
	int c1,c2,x1=0,x2=0,y1=0,y2=0;
	cin >> c1 >> s1[1] >> s1[2] >> s1[3] >> c2 >> s2[1] >> s2[2] >> s2[3];
	if (c1 == c2){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	if (s1[1] == s2[1] && s1[2] == s2[2]){
		cout << 1;
		if ((s1[3]<='C'&&s2[3]<='C')||(s1[3]>'C'&&s2[3]>'C')){
	    	cout << 1;
    		if (s1[3] == s2[3] + 1 || s1[3] == s2[3] - 1){
    	    	cout << 1;
        	}
        	else{
    	    	cout << 0;
    	    }
    	}
    	else{
    		cout << "00";
    	}
	}
	else{
		cout << "000";
	}
	return 0;
}