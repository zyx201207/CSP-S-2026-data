#include<bits/stdc++.h>
using namespace std;
int ac1[5], ac2[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	int lens1 = s1.size();
	int lens2 = s2.size();
	for(int i = 0; i <= 1; i++){
		ac1[i + 1] = c1[i] - 48;
		ac2[i + 1] = c2[i] - 48;
		if(ac1[i + 1] != ac2[i + 1]){
			printf("0000");
			return 0;
		}
	}
	printf("1");
	for(int i = 0; i <= 1; i++){
		if(i <= 1){
			ac1[i + 1] = s1[i] - 48;
			ac2[i + 1] = s2[i] - 48;
		}
		if(ac1[i + 1] != ac2[i + 1]){
			printf("000");
			return 0;
		}
	}
	printf("1");
	if((s1[2] - 64 <= 3 && s2[2] - 64 <= 3) || (s1[2] - 64 >= 4 && s2[2] - 64 >= 4)){
		printf("1");
		if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]){
			printf("1");
			return 0;
		}
		else{
			printf("0");
			return 0;
		}
	}
	else{
		printf("00");
		return 0;
	}
	return 0;
} 
