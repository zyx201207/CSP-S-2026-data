#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int bl=0,app=0;
	string c1,s1,c2,s2;
	char sit[5]={'A','B','C'};
	char sit1[5]={'D','F'};
	cin>>c1>>s1>>c2>>s2;
	//同车箱
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	//同一排
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			bl=1;
		}
		else{
		bl=0;
		}
	}
	if(bl==0){
		cout<<0<<0<<0;
		return 0;
	}
	cout<<bl;
	bl=0;
	//同一侧
	for(int jj=0;jj<3;jj++){
		if(s1[2]==sit[jj]){
			app=1;
		}
		if(s2[2]==sit[jj]){
			bl=1;
		}
		
	}
	if(app&&bl){
		cout<<1;
	}
	else if(!app && !bl){
		cout<<1;
	}
	else{
		cout<<0;
	} 
	//相邻
	if(!(s1[2]==sit[0]&&s2[2]==sit[2])||(s1[2]==sit[2]&&s2[2]==sit[0])){
		cout<<0;
	}
	else{
		cout<<1;
	}
	
	return 0;
}
