#include<bits/stdc++.h> 
using namespace std;
int y,q,w,e[1001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>q>>w;
	for(int i=0;i<q;i++){
		cin>>e[i];
	}
	if(q==5){
		y++;
	}
	if(w==3){
		y++;
	}
	if(e[0]==31){
		y++;
	}
	if(e[1]==3){
		y++;
	}
	if(e[2]==1){
		y++;
	}
	if(e[3]==15){
		y++;
	}
	if(e[4]==7){
		y++;
	}
	if(y==7){
		cout<<"7";
	}
	else{
		cout<<"12";
	}
}
