#include<bits/stdc++.h>
using namespace std;
string cx1,set1,cx2,set2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cx1 >> set1 >> cx2 >> set2;
	if(cx1==cx2){
		if(set1[0]==set2[0]&&set1[1]==set2[1]){
			if(set1[2]=='F'||set1[2]=='D'){
				if(set2[2]=='F'||set2[2]=='D'){
					cout << "1111";
				}else{
					cout << "1100";
				}
			}else{
				if(set2[2]=='A'||set2[2]=='B'||set2[2]=='C'){
					if(abs(set1[2]-set2[2])==1){
						cout << "1111";
					}else{
						cout << "1110";
					}
				}else{
					cout << "1100";
				}
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
