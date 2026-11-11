#include<bits/stdc++.h>
using namespace std;
string r_c1,r_s1,x_c1,x_s1;
bool vis[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r_c1>>r_s1>>x_c1>>x_s1;
	if(r_c1==x_c1){
		cout<<"1";
		vis[1]=true;
	}else{
		cout<<"0";
		vis[1]=false;
	}
	long long num=0,sum=0;
	for(int i=0;i<r_s1.size();i++){
		if(r_s1[i]>='0'&&r_s1[i]<='9'){
			num*=10;
			num+=(r_s1[i]-'0');
		}
	}
		for(int i=0;i<x_s1.size();i++){
		if(x_s1[i]>='0'&&x_s1[i]<='9'){
			sum*=10;
			sum+=(x_s1[i]-'0');
		}
	}
	if(num==sum&&vis[1]==true){
		cout<<"1";
		vis[2]=true;
	}else{
		cout<<"0";
		vis[2]=false;
	}
	long long r_1=0,x_1=0;
	if(x_s1[x_s1.size()-1]<='C'){
		x_1=1;
	}
	if(r_s1[r_s1.size()-1]<='C'){
		r_1=1;
	}
	if(x_1==r_1&&vis[2]==true){
		cout<<"1";
		vis[3]=true;
	}else{
		cout<<"0";
		vis[4]=false;
	}
	if(vis[3]==true){
		if(r_s1[r_s1.size()-1]>'C'&&x_s1[x_s1.size()-1]>'C'){
			cout<<"1";
		}else{
		if(abs(r_s1[r_s1.size()-1]-x_s1[x_s1.size()-1])==1){
			cout<<1;
		}else{
			cout<<"0";
		}	
		}
	}else{
		cout<<"0";
	}
	return 0;
}
