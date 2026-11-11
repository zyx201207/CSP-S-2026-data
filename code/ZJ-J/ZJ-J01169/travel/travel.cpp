#include <bits/stdc++.h>
using namespace std;

string c_1,s_1,c_2,s_2;
int ans[4];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if(c_1==c_2){//同车厢
		ans[0]=1;

		if(s_1[0]==s_2[0] && s_1[1]==s_2[1]){//同一排
			ans[1]=1;

			int si1=0,si2=0;//同一侧
			if(s_1[2]=='D' || s_1[2]=='E')si1=1;
			if(s_2[2]=='D' || s_2[2]=='E')si2=1;
			if(si1==si2){
				ans[2]=1;
				
				if((int)s_1[2]+1==(int)s_2[2] || ((int)s_1[2]-1==(int)s_2[2])){
					ans[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++)cout << ans[i];
	return 0;
}