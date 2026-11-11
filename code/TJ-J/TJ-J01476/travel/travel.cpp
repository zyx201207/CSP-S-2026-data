#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != c2){
		cout << 0 << 0 << 0 << 0;
		return 0;
	}else{
		cout << 1;
	}//不在一节车厢 
	
	string col1,col2;
	col1 = s1.substr(0,2);
	col2 = s2.substr(0,2);
	
	stringstream ss1(col1),ss2(col2);
	
	int int_col1,int_col2;
	ss1 >> int_col1;
	ss2 >> int_col2;
	
	if(int_col1 != int_col2){
		cout << 0 << 0 << 0;
		return 0;

	}else{
		cout << 1;
	}//在一节车厢，不在同一排
	
	int ans2;
	
	if(abs(s1[2]-s2[2]) != 1){
		ans2 = 0;
	}else{
		ans2 = 1;
	}//不挨着 
	
	int ans1;
	
	if((s1[2]=='C' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='C')){
		ans1 = 0;
	}else{
		ans1 = 1;
	}//挨着，但是隔着过道
	
	if(ans1 == 0){
		ans2 = 0;
	}
	
	cout << ans1 << ans2; 
	
	return 0;
}
