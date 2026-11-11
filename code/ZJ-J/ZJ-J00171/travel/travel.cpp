#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans[10];
	if(c1 == c2){
		ans[1]=1;
	}
	else ans[1] = 0;
	int b = 0;
	for(int i = 0;i < 2;i++){
		if(s1[i] == s2[i] && ans[1] == 1){
			b++;
		}
	}
	if(b == 2){
		ans[2]=1;
	}else ans[2]=0;
	if(ans[2] == 1 && (((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A'))||((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')))){
		ans[3]=1;
	}else ans[3]=0;
	if(ans[3]==1&&(s1[2]-s2[2] == 1 || s1[2]-s2[2] == -1)){
		ans[4]=1;
	}else ans[4]=0;
	for(int i = 1;i <= 4;i++){
		cout << ans[i];
	}
	return 0;
}
