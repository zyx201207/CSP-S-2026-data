#include <bits/stdc++.h>
using namespace std;
struct s{
	string num;//记录车厢编号
	string seat;//记录排和列 
	string lie;
	string pai;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s a,b;
	cin>>a.num >>a.seat >>b.num >>b.seat ;
	a.lie=a.seat[0]+a.seat[1];
	b.lie=b.seat[0]+b.seat[1];
	a.pai=a.seat[2];
	b.pai=b.seat[2];
	if(a.num ==b.num ){
		//ans[0]='1';
	}else{
		cout<<"0000";
		return 0;
	}if(a.lie==b.lie){
		//ans[1]='1';
	}else{
		cout<<"1000";
		return 0;
	}if((a.pai == "A"&&b.pai =="B")||(a.pai == "B"&&b.pai =="A")||(a.pai == "B"&&b.pai =="C")||(a.pai == "C"&&b.pai =="B")||(a.pai == "A"&&b.pai =="C")||(a.pai == "C"&&b.pai =="A")||(a.pai == "D"&&b.pai =="F")||(a.pai == "F"&&b.pai =="D")){//是否属于同一侧 
		//ans[2]='1';
	}else{
		cout<<"1100";
		return 0;
	}
	if((a.pai == "A"&&b.pai =="B")||(a.pai == "B"&&b.pai =="A")||(a.pai == "B"&&b.pai =="C")||(a.pai == "C"&&b.pai =="B")||(a.pai == "D"&&b.pai =="F")||(a.pai == "F"&&b.pai =="D")){//是否相邻 
		//ans[3]='1';
	}else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
	//删掉输出的endl 
} 
