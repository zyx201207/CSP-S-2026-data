#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	int c1,s1s,c2,s2s;
	string s1z,s2z;
	cin>>c1>>s1s>>s1z>>c2>>s2s>>s2z;
	
	if (c1==c2){
		cout<<1;
		
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if (s1s==s2s){
		cout<<1;
		
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if ((s1z<"D"&&s2z<"D")||(s1z>"C"&&s2z>"C")){
		cout<<1;
		
	}else{
		cout<<0<<0;
		return 0;
	}
	if ((s1z=="A"&&s2z=="B")||(s1z=="B"&&s2z=="A")||(s1z=="B"&&s2z=="C")||(s1z=="C"&&s2z=="B")||(s1z=="D"&&s2z=="F")||(s1z=="F"&&s2z=="D")){
		cout<<1;
	}else{
		cout<<0;
		return 0;
		
	}
	
	
	return 0;
}
