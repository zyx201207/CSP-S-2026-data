#include<bits/stdc++.h>
using namespace std;
string a,b;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(x[0]==y[0]&&x[1]==y[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(x[2]<='C'&&y[2]<='C'||x[2]>='D'&&y[2]>='D'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(x[2]+1==y[2]||y[2]+1==x[2]){
		cout<<1;
	}else{
		cout<<"0";
	}
	return 0;
}