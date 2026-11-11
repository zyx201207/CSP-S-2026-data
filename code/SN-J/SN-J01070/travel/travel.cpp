#include<bits/stdc++.h>
using namespace std; 
int main(){
	
	
	freopen("tralvel.in","r",stdin);
	freopen("tralvel.out","w",stdout);
	
	string y1,y2,y3,y4;
	cin>>y1>>y2>>y3>>y4;
	if(y1==y3){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(y2[3]==y4[3]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(y2[4]+1==y4[4]){
		cout<<"11";
	}else{
		cout<<"00";
	}

	
	
	return 0;
}
