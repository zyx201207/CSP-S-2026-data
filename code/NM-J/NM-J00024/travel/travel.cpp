#include <bits/stdc++.h>
using namespace std;
bool p1(char c1, char c2){
	if(c1>='A' && c1<='C' && c2>='A' && c2<='C')return 1;
	if(c1>='D' && c1<='F' && c2>='D' && c2<='F')return 1;
	return 0;
} 
bool p2(char c1, char c2){
	if(c1=='F')c1=='E';
	if(c2=='F')c2=='E';
	int div=abs(c1-c2);
	return div==1;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int boxa, boxb, linea, lineb;
	char seata, seatb;
	bool ans[4]={0};
	scanf("%d %d%c %d %d%c", &boxa, &linea, &seata, &boxb, &lineb, &seatb);
	if(boxa==boxb){
		ans[0]=1;
		if(linea==lineb){
			ans[1]=1;
			if(p1(seata, seatb)){
				ans[2]=1;
				if(p2(seata, seatb)){
					ans[3]=1;
				}
			}
		}
	}
	string ss="0000";
	for(int i=0; i<4; i++){
		if(ans[i])ss[i]++;
	}
	cout<<ss;
	return 0;
}
