#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b,c,d;
	string e,f;
	cin>>a>>b;
	cin>>e;
	cin>>c>>d;
	cin>>f;
	if(a==c && b==d && (e=="A" && f=="B" || e=="B" && f=="A" || e=="B" && f=="C" || e=="C" && f=="B" || e=="D" && f=="F")){
		cout<<"1111";
	}
	else if(a==c && b==d && (e=="A" && f=="C" || e=="C" && f=="A")){
		cout<<"1110";
	}
	else if(a==c && b==d){
		cout<<"1100";
	}
	else if(a==c){
		cout<<"1000";
		}else{
			cout<<"0000";
		}
	return 0;
}
