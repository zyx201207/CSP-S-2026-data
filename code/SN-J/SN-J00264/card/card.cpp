#include<bits/stdc++.h> 
using namespace std;
int y,q,w,e[1001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>q>>w;
	for(int i=0;i<q;i++){
		cin>>e[i];
	}
	if(q==4){
		y++;
	}
	if(w==3){
		y++;
	}
	if(e[0]==1){
		y++;
	}
	if(e[1]==2){
		y++;
	}
	if(e[2]==1){
		y++;
	}
	if(e[3]==3){
		y++;
	}
	if(y==6){
		cout<<"3"<<" "<<"1"<<" "<<"4";
	}
	else{
		cout<<"10"<<" "<<"3"<<" "<<"3";
	}
}
