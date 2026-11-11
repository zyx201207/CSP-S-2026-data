#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool flag1 = 1;//车厢
	for(int i = 0;i<=2 && flag1;i++){  
		if(c1[i]!=c2[i]) flag1 = 0;
	}
	cout << flag1;
	
	bool flag2 = flag1;//同一排 
	for(int i = 1;i<=1 && flag2;i++){
		if(s1[i]!=s2[i])flag2=0;
	}
	cout << flag2;
	
	bool side1=0,side2=0,flag3=flag2;//同侧  1上 0下 
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')side1 = 0;else side1 = 1;
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')side2 = 0;else side2 = 1;
	flag3 = (side1==side2)&&flag3;
	cout << flag3;
	
	bool flag4 = flag3;//相邻
	if(abs(s1[2]-s2[2])!=1)flag4 = 0;
	cout << flag4;		
	return 0;
}
