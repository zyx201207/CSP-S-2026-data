#include<bits/stdc++.h>
using namespace std;
string cx1;
string cx2;
string seat1;
string seat2;
int ans[8];
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cx1 >> seat1 >> cx2 >> seat2;
	if(cx1 == cx2){
		ans[0] = 1;
		if(seat1[0] == seat2[0] && seat1[1] == seat2[1]){
			ans[1] = 1;
			int yes = 0;
			if(seat1[2] <= 'C' && seat1[2] >= 'A'){
				if(seat2[2] <= 'C' && seat2[2] >= 'A') yes = 1;
			}
			if(abs( seat1[2] - seat2[2] ) == 2 && (seat1[2] != 'D' || seat2[2] != 'D')){
				yes = 1;
				ans[3] = 1;
			}
			
			
			if(yes){
				ans[2] = 1;
				if( ( abs(seat1[2] - seat2[2]) == 1 )  && seat1[2] != 'D' && seat2[2] != 'D'){
					ans[3] = 1;
				}
				
			}
			
			
		}
	}
	for(int i = 0; i < 4; i++){
		cout << ans[i];
	}
	return 0;
}
