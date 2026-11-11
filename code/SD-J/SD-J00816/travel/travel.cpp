#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1_j,y1_j,hl_j=0;
	string x2_j,y2_j;
	cin>>x1_j>>x2_j>>y1_j>>y2_j;
	if(x1_j==y1_j){
		cout<<1;
		hl_j+=1;
	}
	else cout<<0;
	if((x2_j[0]==y2_j[0]&&x2_j[1]==y2_j[1])&&hl_j==1){
		cout<<1;
		hl_j+=1;
	}else cout<<0;
	if((hl_j==2)&&(((x2_j[2]=='A'||x2_j[2]=='B'||x2_j[2]=='C')&&(y2_j[2]=='A'||y2_j[2]=='B'||y2_j[2]=='C'))||((x2_j[2]=='D'||x2_j[2]=='E')&&(y2_j[2]=='D'||y2_j[2]=='E')))){
		cout<<1;
		hl_j+=1;
	}else cout<<0;
	if((hl_j==3)&&(((x2_j[2]=='A'&&y2_j[2]=='B')||(x2_j[2]=='B'&&y2_j[2]=='C')||(x2_j[2]=='D'&&y2_j[2]=='E'))||(x2_j[2]=='B'&&y2_j[2]=='A')||(x2_j[2]=='C'&&y2_j[2]=='D')||(x2_j[2]=='E'&&y2_j[2]=='D'))){
		cout<<1;
	}else cout<<0;
	return 0;
}
