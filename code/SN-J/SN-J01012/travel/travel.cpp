#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);




	string c_r,s_r,c_x,s_x;
	cin>>c_r>>s_r>>c_x>>s_x;
	//两张车票对应的座位是否在同一节车厢；
	if(c_x==c_r){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	// 两张车票对应的座位是否在同一节车厢的同一排；
	if(s_r[0]==s_x[0]&&s_r[1]==s_x[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
	if(s_r[2]>='D'&&s_x[2]>='D'||s_r[2]<'D'&&s_x[2]<'D'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	//张车票对应的座位是否相邻。
	if(abs(s_r[2]-s_x[2])<=1){
		cout<<'1';
	}
	else{
		cout<<"0";
	}
	
	
	
	return 0;
}
