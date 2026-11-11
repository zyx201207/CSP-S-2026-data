#include <bits/stdc++.h>
using namespace std;
int c1,c2;string s1,s2;
int vis[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	//判断 是否 在 同一个 车厢
	if(c1 == c2) vis[0] = 1;
	//判断 是否 在 同一排
	if(s1[0] == s2[0] && s1[1] == s2[1] && vis[0] == 1) vis[1] = 1;
	//判断是否 在 同一侧 且 同一排
	if(vis[1] == 0 || vis[0] == 0){
		vis[2] = 0;//都不在 同一排 不可能在一侧
	}else{
		if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) vis[2] = 1;
		if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) vis[2] = 1;
	}
	//判断 是否相邻
	if(vis[0] == 0 || vis[1] == 0 || vis[2] == 0){
		vis[3] = 0;
	}else{
		// abc 相 邻 
		if(s1[2] == 'A' && s2[2] == 'B') vis[3] = 1;
		else if(s1[2] == 'B' && s2[2] == 'C') vis[3] = 1;
		else if(s2[2] == 'A' && s1[2] == 'B') vis[3] = 1;
		else if(s2[2] == 'B' && s1[2] == 'C') vis[3] = 1;
		
		// df 相 邻
		else if(s1[2] == 'D' && s2[2] == 'F') vis[3] = 1;
		else if(s2[2] == 'D' && s1[2] == 'F') vis[3] = 1;
	}
	for(int i=0;i<4;i++) cout << vis[i];
	return 0;
} 
