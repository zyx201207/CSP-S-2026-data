#include<bits/stdc++.h>
using namespace std;
int r1,x1;
string r2,x2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	int r2d=(r2[0]-'0')*10+(r2[1]-'0');
	int x2d=(x2[0]-'0')*10+(x2[1]-'0');
	if(r1==x1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(r2d==x2d){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(r2[2]>='D' && x2[2]>='D'){
		cout<<1; 
	}else if(r2[2]<='C' && x2[2]<='C'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(max(r2[2],x2[2])-min(r2[2],x2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
