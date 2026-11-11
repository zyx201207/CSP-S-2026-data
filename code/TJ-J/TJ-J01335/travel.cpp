#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans1,ans2,s1,s2,a1ans,a2ans;
	string a = "ABCDF";
	char a1,a2;
	cin >> ans1 >> s1 >> a1 >> ans2 >> s2 >> a2;
	if(ans1 != ans2){
		cout << "0000";
		return 0;
	}
	if(s1 != s2){
		cout << "1000";
		return 0;
	}
	for(int i = 0;i < 5;i++){
		if(a[i] == a1){
			a1ans = i;
		}
		if(a[i] == a2){
			a2ans = i;
		}
	}
	if(((a1ans <= 2) && (a2ans <= 2)) || ((a1ans > 2) && (a2ans > 2))){
		
	}else{
		cout <<"1100";
		return 0;
	}
	if((a1ans + 1 == a2ans) || (a1ans - 1 == a2ans)){
		cout <<"1111";
	}else{
		cout << "1110";
	}
	return 0;
} 
