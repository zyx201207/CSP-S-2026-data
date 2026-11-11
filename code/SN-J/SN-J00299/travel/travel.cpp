#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,z,n;
	int num,size;
	char a,b[100],c,d[100];
//从文件travel.in 中读入数据。
	cin>>a>>b[0]>>c>>d[0];//输入的第一行包含四个字符串c1,s1,c2,s2，分别表示小R的车票上的车厢号、座位
	
	if(b[0] == d[0]){
		y = 0;
	}
	else{
		y = 1;
	}
	
	if(b[1] == d[1]){
		z = 1;
	}
	else{
		z = 0;
	}
	
	if(b[2] == d[2]){
		n = 1;
	}
	else{
		n = 0;
	}
	
	if(a==c){
		x = 1;
	}
	else if(a!=c){
		x = 0; 
		y = 0;
		z = 0;
		n = 0;
	}			
	
	cout<<x<<y<<z<<n;
	return 0;
}
 
