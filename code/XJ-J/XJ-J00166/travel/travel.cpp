#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) 
        cout << "0000" << endl;
    else{
    	if ((s1[0] != s2[0]) || (s1[1] != s2[1]))
            cout << "000";
	    else{
	    	cout << "1";
	    	if (((s1[2] == 'C') && (s2[2] == 'D')) || ((s1[2] == 'D') && (s1[2] == 'C')))
	    	    cout << "00";
	        else{
	        	cout << "1";  
	    	    char c1 = s1[2],c2 = (int)c1+1,c3 = (int)c3-1;
	    	    if (s2[2] == c2 || s2[2] == c3)
	    	        cout << "1";
				else 
				    cout << "0";          
			} 
	 	}    	
	}
} 
