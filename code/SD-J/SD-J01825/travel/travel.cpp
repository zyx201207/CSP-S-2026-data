#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,ss1,ss2,res;
	bool flag1 = true,flag2 = true,flag3 = true;
	res = "";
	cin>>s1>>s2>>ss1>>ss2;
	if(s1 == ss1){
		res += '1';
	}
	else{
		res += '0';
		flag1 = false;
	}
	
	
	if(flag1 == false){
		res += '0';
		flag2 = false;
	}
	else{
		if(s2[0] == ss2[0] && s2[1] == ss2[1]){
			res += '1';
		}
		else{
			res += '0';
			flag2 = false;
		}
	}
	
	if(flag2 == false){
		res += '0';
		flag3 = false;
		
	}
	else{
		if(((s2[2] >= 'A' && s2[2] <= 'C') && (ss2[2] >= 'A' && ss2[2] <= 'C')) || ((s2[2] >= 'D' && s2[2] <= 'F') && (ss2[2] >= 'D' && ss2[2] <= 'F'))){
			res += '1';
		}
		else{
			res += '0';
			flag3 = false;
		}
	}
	
	
	
	
	if(flag3 == false){
		res += '0';
	}
	else{
		if(s2[2] + 1 == ss2[2] || s2[2] - 1 == ss2[2]){
			res += '1';
		}
		else{
			res += '0';
		}
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
