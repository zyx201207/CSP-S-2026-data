//刘雨辰 SN-J00812 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1"<<" ";
	}
	else{
		cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0";
		return 0;
	}
	if(b[0]==d[0] and b[1]==d[1]){
		cout<<"1"<<" ";
	}
	else{
		cout<<"0"<<" "<<"0"<<" "<<"0";
		return 0;
	}
	if(b[2]>'C'and d[2]>'C' or b[2]<'D' and d[2]<'D'){
		cout<<"1"<<" ";
	}
	else{
		cout<<"0"<<" "<<"0";
		return 0;
	}	
	if(b[2]+1==d[2] or b[2]-1==d[2]){
		cout<<"1"<<" ";
	}
	else{
		cout<<"0"<<" ";
		return 0;
	}		
	return 0;
}
