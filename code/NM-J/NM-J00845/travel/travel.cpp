#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	int a,b;
	cin>>n>>a>>m>>b;
	int s[10];
	if(n!=m){
		s[0] = 1;
	}
	else{
		s[0] = 0;
	}
	if(a-b<6&&a-b>-6){
		s[1] = 1;
	}
	else{
		s[1] = 0;
	}
	if(a-b<3&&a-b>-3){
		s[2] = 1;
	}
	else{
		s[2] = 0;
	}
	if(a-b<2&&a-b>-2){
		s[3] = 1;
	}
	else{
		s[3] = 0;
	}
	for(int i = 0;i<4;i++){
		cout<<s[i];
	}
	return 0;
}
