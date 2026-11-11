#include<bits/stdc++.h>
using namespace std;
string c_1,c_2,s_1,s_2;
bool f_1,f_2,f_3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1 == c_2){
		cout<<1;
		f_1 = 1;
	}
	else cout<<0;
	
	if(s_1[0] == s_2[0] and s_1[1] == s_2[1] and f_1){
		cout<<1;
		f_2 = 1;
	}
	else cout<<0;
	
	if(f_2){
		if(s_1[2] == 'A' or s_1[2] == 'B' or s_1[2] == 'C' and s_2[2] == 'A' or s_2[2] == 'B' or s_2[2] == 'C')	cout<<1;
		else if(s_1[2] == 'D' or s_1[2] == 'F' and s_2[2] == 'D' or s_2[2] == 'F')cout<<1;
		else cout<<0;
		f_3 = 1;
}
	else {
		cout<<0;
	}

	if(f_3){
		if(s_1[2] == 'A' and s_2[2] == 'B')cout<<1;
		else if(s_1[2] == 'B' and s_2[2] == 'A')cout<<1;
		else if(s_1[2] == 'B' and s_2[2] == 'C')cout<<1;
		else if(s_1[2] == 'C' and s_2[2] == 'B')cout<<1;
		else if(s_1[2] == 'D' and s_2[2] == 'F')cout<<1;
		else if(s_1[2] == 'F' and s_2[2] == 'D')cout<<1;
		else cout<<0;
}
	else{
		cout<<0;
	
	}
		
	return 0;
} 
