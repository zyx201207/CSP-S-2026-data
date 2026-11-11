//SN-J00779 王梓翰 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int p1,p2;
char s1,s2;
bool check1(char a,char b){
	int x,y;
	if(a!='D') x=a-'A'+1;
	else x=5;
	if(b!='D') y=b-'A'+1;
	else y=5; 
	return (x>4)==(y>4);
}
bool check2(char a,char b){
	if(!check1(a,b)) return 0;
	int x,y;
	if(a!='D') x=a-'A'+1;
	else x=5;
	if(b!='D') y=b-'A'+1;
	else y=5;
	return ((x-y)==1)||((x-y)==-1);
}
int main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c1,&p1,&s1,&c2,&p2,&s2);
	// i:c1==c2 ii:(c1==c2)&&(p1==p2) iii:(c1==c2)&&(p1==p2)&&check1(s1,s2) iv:(c1==c2)&&(p1==p2)&&check1(s1,s2)&&check2(s1,s2)
	bool i=(c1==c2),ii=((c1==c2)&&(p1==p2)),iii=((c1==c2)&&(p1==p2)&&check1(s1,s2)),iv=((c1==c2)&&(p1==p2)&&check1(s1,s2)&&check2(s1,s2));
	cout<<i<<ii<<iii<<iv;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//T1 : R3D/OR4NG3
//15min ez
