#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char s11 = s1[0], s12 = s1[1], s21 = s2[0], s22 = s2[1], s13 = s1[2], s23 = s2[2];
	if(c1 == c2){
		cout << "1";
		if(s11 == s21 && s12 == s22){
	    	cout << "1";
	    	int m1 = s13, m2 = s23;
	    	if(m1 == 70) m1--;
	    	if(m2 == 70) m2--;
	    	int m3 = abs(m1 - m2);
	    	if( m3 <= 2 && ((m1 >= 68 && m2 >= 68) || (m1 <= 67 && m2 <= 67))){
	    		cout << "1";
	    		if(m3==1){
	    			cout<<"1";
				}
				else cout<<"0";
	    	}
	    	else cout << "00";
	    }
	    else cout<<"000";
	}
	else cout << "0000";
	
	return 0;
} 
