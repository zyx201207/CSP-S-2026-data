#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	string an;
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3){
		an += "1";
		if(c2[0] == c4[0] && c2[1] == c4[1]){
			an += "1";
			if(c2[2] <= 'C' && c4[2] <= 'C' || c2[2] > 'C' && c4[2] > 'C'){
				an += "1";
				if(c2[2] - c4[2] == 1 || c4[2] - c2[2] == 1){
					an += "1";
				}
				else{
					an += "0";
				}
			}
			else{
				an += "00";
			}
		}
		else{
			an += "000";
		}
	}
	else{
		an += "0000";
	}
	cout << an;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
