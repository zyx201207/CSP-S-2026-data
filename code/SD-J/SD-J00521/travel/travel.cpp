#include<bits/stdc++.h>
using namespace std;
string xiao_R_chexiang,xiao_X_chexiang,xiao_R_zuohao,xiao_X_zuohao;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>xiao_R_chexiang>>xiao_R_zuohao>>xiao_X_chexiang>>xiao_X_zuohao;
	if(xiao_R_chexiang!=xiao_X_chexiang){
		cout<<"0000\n";
		return 0;
	}
	if(xiao_R_zuohao[0]!=xiao_X_zuohao[0]||xiao_R_zuohao[1]!=xiao_X_zuohao[1]){
		cout<<"1000\n";
		return 0;
	}
	if(xiao_R_zuohao[2]=='F'&&(xiao_X_zuohao[2]=='A'||xiao_X_zuohao[2]=='B'||xiao_X_zuohao[2]=='C')||xiao_X_zuohao[2]=='F'&&(xiao_R_zuohao[2]=='A'||xiao_R_zuohao[2]=='B'||xiao_R_zuohao[2]=='C')||xiao_R_zuohao[2]=='D'&&(xiao_X_zuohao[2]=='A'||xiao_X_zuohao[2]=='B'||xiao_X_zuohao[2]=='C')||xiao_X_zuohao[2]=='D'&&(xiao_R_zuohao[2]=='A'||xiao_R_zuohao[2]=='B'||xiao_R_zuohao[2]=='C')){
		cout<<"1100\n";
		return 0;
	}
	if(xiao_R_zuohao[2]=='A'&&xiao_X_zuohao[2]=='C'||xiao_X_zuohao[2]=='A'&&xiao_R_zuohao[2]=='C'){
		cout<<"1110\n";
		return 0;
	}
	cout<<"1111\n";
	return 0;
} 
