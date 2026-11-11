#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,a4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[1] = c2[1]){
		a1 == 1;
    }
	else{
		a1 == 0;
	}
	
	if(s1[1] = s2[1]){
		a2 == 1;
	}
	else{
		a2 == 0;
	}
	
	if((s1[2]=='D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
		a3 == 1;
	}
	else{
		a3 == 0;
	}
	
	if(a3 == 0){
		if((s1[2]=='A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2]=='A' || s2[2] == 'B' || s2[2] == 'C')){
		    a3 == 1;
	    }
	    else{
		    a3 == 0;
	    }
    }
	
	if(a3 == 0){
	    a4 == 0;
	}
	else{
		if(s1[2] == 'B' || s1[2] == 'D' || s1[2] == 'F'){
			a4 == 1;
		}
		else if(s2[2] == 'B' || s2[2] == 'D' || s2[2] == 'F'){
			a4 == 1;
		}
		else{
			a4 == 0;
		}
	}
	cout << a1 << a2 << a3 << a4;
	return 0;
}