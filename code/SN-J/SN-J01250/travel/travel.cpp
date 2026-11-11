#include <bits/stdc++.h>
using namespace std;
int n,x;
string y,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>x>>y;
	if(n!=x){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	if(m[0]+m[1]!=y[0]+y[1]){
		cout<<"000";
		return 0;
	}else{
		cout<<1;
	}
	if(m[2]=='A'){
		if(y[2]=='B'){
			cout<<"11";
		}else if(y[2]=='C'){
			cout<<"10";
		}else{
			cout<<"00";
		}
	}else if(m[2]=='B'){
		if(y[2]=='A' || y[2]=='C'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else if(m[2]=='C'){
		if(y[2]=='B'){
			cout<<"11";
		}else if(y[2]=='A'){
			cout<<"10";
		}else{
			cout<<"00";
		}
	}else if(m[2]=='D'){
		if(y[2]=='E'){
			cout<<"11";
		}else{
			cout<<"10";
		}
	}else{
		if(y[2]=='D'){
			cout<<"11";
		}else{
			cout<<"10";
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
