#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}if(b==d){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
		
	}
	
	return 0;
}
