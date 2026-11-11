#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int arr[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	if(a1 == b1){
		arr[1] = 1;
		if(a2[0] == b2[0] && a2[1] == b2[1]){
			arr[2] = 1;
			if(((a2[2] == 'A' || a2[2] == 'B') || (a2[2] == 'C' || 0)) && ((b2[2] == 'A' || b2[2] == 'B') || (b2[2] == 'C' || 0)) ||
			((a2[2] == 'D' && b2[2] == 'F') || (a2[2] == 'F' && b2[2] == 'D'))){
				arr[3] = 1;
				if(abs(a2[2]-b2[2]) == 1){
					arr[4] = 1;
				}
			}
		}
	}
	for(int i = 1;i <= 4;i++){
		cout << arr[i];
	}
	
	return 0;
}
