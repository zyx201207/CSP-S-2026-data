#include<bits/stdc++.h>
using namespace std;
struct Node{
	string che,zuo;
};
bool cxp(char x1,char x2){
	return (int(x1)+1==int(x2))||(int(x1)-1==int(x2));
}
bool cnp(char x,char y){
	return (x>='D'&&y>='D')||(x<='C'&&y<='C');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Node a,b;
	cin>>a.che>>a.zuo>>b.che>>b.zuo;
	if(a.che==b.che){
		printf("%d",1);
	}else{
		printf("%d%d%d%d",0,0,0,0);
		return 0; 
	}
	if(a.zuo[1]==b.zuo[1]){
		printf("%d",1);
	}else{
		printf("000");
		return 0;
	}
	if(cnp(a.zuo[2],b.zuo[2])){
		printf("%d",1);
	}else{
		printf("00");
		return 0;
	}
	if(cxp(a.zuo[2],b.zuo[2])){
		printf("%d",1);
	}else{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
