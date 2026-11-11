#include<bits/stdc++.h>
using namespace std;
int c1,c3;
string c2,c4;
char l[4]={' ','A','B','C'},r[3]={' ','E','F'};
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1==c3){
		ans[1]=1;
	}
	else{
		for(int i=1;i<=4;i++){
			cout << 0;
		}
		return 0;
	}
	if(c2[0]==c4[0] && c2[1]==c4[1]){
		ans[2]=1;
		if(c2[2]>=l[1] && c2[2]<=l[3]){
			if(c4[2]>=l[1] && c4[2]<=l[3]){
				ans[3]=1;
				if(c2[2]+1==c4[2] || c2[2]-1==c4[2]){
					ans[4]=1;
				}
			}
			else{
				ans[3]=0;
				ans[4]=0;
			}
		}
		else if(c2[2]>=r[1] && c2[2]<=r[2]){
			if(c4[2]>=r[1] && c4[2]<=r[2]){
				ans[3]=1;
				ans[4]=1;
			}
			else{
				ans[3]=0;
				ans[4]=0;
			}
		}
	}
	else{
		ans[2]=0;
	}
	for(int i=1;i<=4;i++){
		cout << ans[i];
	}
	return 0;
}
