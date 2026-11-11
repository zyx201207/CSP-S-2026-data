#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int count1 = 0;
	for(int i = 0;i<2;i++){
		if(s1[i] == s3[i]) count1++;
	}
	if(count1 == 2){
		cout<<1;
		int count2 = 0;
		for(int i = 0;i<2;i++){
			if(s2[i] == s4[i]) count2++;
		}
		if(count2 == 2) cout<<1;
		else cout<<0;
		int count3 = 0;
		if(s2[2] < 'D' && s4[2] < 'D' && count2 == 2){
			count3 = 1;
		}
		if(s2[2] >= 'D' && s4[2] >= 'D' && count2 == 2){
			count3 = 1;
		}
		cout<<count3;
		int count4 = 0;
		if(count3 == 1){
			if(s2[2] == char(s4[2]-1) || char(s2[2]-1) == s4[2]){
				count4 = 1;
			}
		}
		cout<<count4;
	}
	return 0;
}
