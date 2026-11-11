#include<bits/stdc++.h>
using namespace std;
int i,j;
int c1,c2;
char s1[5];
char s2[5];
int q1,q2,q3,q4;
int main(){

	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		q1=1;
	}									//先确定是否在同一车厢，如果在就输出1，q1也等于1，后边判断前先判断前一个q是否等于1，如果为0直接输出0且q等于0 
	else{
	cout<<0;
	q1=0;
	}
	cout<<c1<<c2<<s1[1]<<s2[1];
	
	
}
//freopen("文件名.in","r","stdin") 
//freopen("文件名.out","w","stdout") 

//freopen("travel.in","r","stdin")
//freopen("travel.out","w","stdout")
