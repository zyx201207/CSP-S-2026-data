#include<bits/stdc++.h> 
using namespace std;
string c[8];
string s[8];
int zp1, zp2;
char zl1, zl2;
bool pd(char z1, char z2){
	if(z1>='A'&&z1<='C'&&z2>='A'&&z2<='C'){
		if((z1=='A'&&z2=='C')||(z1=='C'&&z2=='A')) return 0;
		else return 1;
	}else{
		return 1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!记得取消注释 
	
	//输入
	cin >>  c[1] >> s[1] >> c[2] >> s[2];
	zp1 = (s[1][0]-'0')*10 + s[1][1]-'0';
	zl1 = s[1][2];
	zp2 = (s[2][0]-'0')*10 + s[2][1]-'0';
	zl2 = s[2][2];
	//判断+输出 
	//两张车票对应的座位是否在同一节车厢；
	//两张车票对应的座位是否在同一节车厢的同一排；
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
	//两张车票对应的座位是否相邻。
	if(c[1]==c[2]){
		cout << 1;
		if(zp1==zp2){
			cout << 1;
			if((zl1>='A'&&zl1<='C'&&zl2>='A'&&zl2<='C')||(zl1>='D'&&zl1<='F'&&zl2>='D'&&zl2<='F')){
				cout << 1;
				if(pd(zl1, zl2)){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << 0 << 0;
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
 		
	return 0;
}
