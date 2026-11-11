#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y; //第几个车厢 
	string x1,y1; //座位 
	cin>>x>>x1>>y>>y1;
	int a=(x1[0]-'0')*10+(x1[1]-'0'); //座位 
	int b=(y1[0]-'0')*10+(y1[1]-'0'); //座位
	
	char fx=x1[2];
	char fy=y1[2];
	if(x==y) cout<<1; //同一车厢 
	else{
		cout<<"0000";
		return 0;
	}
	
	if(a==b) cout<<1;//同一排 
	else {
		cout<<"000";
		return 0;
	}
	
	bool flag=0;//同一侧 
	if('A'<=fx&&fx<='C'&&'A'<=fy&&fy<='C') {//同为左 
		flag=1;
		cout<<1;
	}else if('D'<=fx&&fx<='F'&&'D'<=fy&&fy<='F'){ //同为右，直接相邻 
		cout<<11;
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if(flag==1&&abs((fx-'0')-(fy-'0'))==1){ //左边相邻 
		cout<<1;
	} 
	else{
		cout<<"0"; 
		return 0;
	}
} 
