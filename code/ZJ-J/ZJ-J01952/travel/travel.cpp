#include<bits/stdc++.h> 
using namespace std;
string m,y;
int n,x,ans=0,sum=0;
bool a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>x>>y;
	if(n!=x){
		cout<<"0000"<<'\n';
		return 0;
	}
	ans=(int)(m[0]-'0')*10+(int)(m[1]-'0');
	sum=(int)(y[0]-'0')*10+(int)(y[1]-'0');
	if(ans!=sum){
		cout<<"1000"<<'\n';
		return 0;
	}
	if(m[2]=='A'||m[2]=='B'||m[2]=='C'){
		a=1;
	}
	if(m[2]=='D'||m[2]=='F'){
		a=0;
	}
	if(y[2]=='A'||y[2]=='B'||y[2]=='C'){
		b=1;
	}
	if(y[2]=='D'||y[2]=='F'){
		b=0;
	}
	if(a!=b){
		cout<<"1100"<<'\n';
		return 0;
	}
	if(m[2]=='D'&&y[2]=='F'||m[2]=='F'&&y[2]=='D'||m[2]=='A'&&y[2]=='B'||m[2]=='B'&&y[2]=='C'||m[2]=='B'&&y[2]=='A'||m[2]=='C'&&y[2]=='B'){
		cout<<"1111"<<'\n';
		return 0;
	}else{
		cout<<"1110"<<'\n';
		return 0;
	}
	return 0;
}
