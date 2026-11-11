#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a = 0,b = 0,c = 0;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<1;
		a = 1;
	}else{
		cout<<0;
	}
	
	if(s1[0] == s2[0] and s1[1] == s1[1]){
		cout<<1;
		b = 1;
	}else{
		cout<<0;
	}
	
	if((s1[2] == 'A' and s2[2] == 'B') or (s1[2] == 'A' and s2[2] == 'C') or (s1[2] == 'B' and s2[2] == 'C') or (s1[2] == 'B' and s2[2] == 'A') or (s1[2] == 'C' and s2[2] == 'A') or (s1[2] == 'C' and s2[2] == 'B') or (s1[2] == 'D' and s2[2] == 'F') or (s1[2] == 'F' and s2[2] == 'D')){
		cout<<1;
		c = 1;
	}else{
		cout<<0;
	}
	
	if(a == 1 and b == 1 and c == 1 and !(s1[2] == 'A' and s2[2] == 'C') and !(s1[2] == 'C' and s2[2] == 'A')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
