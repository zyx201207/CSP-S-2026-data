#include <bits/stdc++.h>
using namespace std;
string s1[2];
string s2[2];
char a[5] = {'A','B','C','D','E'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1[0] >> s1[1] >> s2[0] >> s2[1];
	int idx1=0,idx2=0;
	for(int i = 0; i < 5; i++){
		if(s1[1][2]==a[i]){
			idx1=i+1;
			break;
		}
	}
	for(int i = 0; i < 5; i++){
		if(s2[1][2]==a[i]){
			idx2=i+1;
			break;
		}
	}
	int count = 4;
	if(s1[0]==s2[0]){
	}else{
		cout << "0000";
		return 0;
	}
	if(s1[1][0]==s2[1][0] && s1[1][1]==s2[1][1]){
	}else{
		cout << "1000";
		return 0;
	}
	if((idx1<=3 && idx2<=3) || (idx1>=4 && idx2>=4)){
	}else{
		cout << "1100";
		return 0;
	}
	if(idx1-idx2==1 || idx2-idx1==1){
	}else{
		cout << "1110";
		return 0;
	}
	cout << "1111";

	
	return 0;
}
