#include<iostream>
#include<cmath>
using namespace std;
struct travel{
	int xiang;
	string id;
	int x,y;
	char xy;
}a,b;
int xx(int a){
	if(a>=0){
		return a;
	}
	return -a;
}
int as[6]={0,0,0,1,-1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.xiang>>a.id;
	a.x=10*a.id[0]+a.id[1]-'0'*11;
	a.y=a.id[2]-'A';
	a.xy=a.id[2];
	cin>>b.xiang>>b.id;
	b.x=10*b.id[0]+b.id[1]-'0'*11;
	b.y=b.id[2]-'A';
	b.xy=b.id[2];
	if(a.xiang==b.xiang){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a.x==b.x){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(as[a.y]==as[b.y]){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(xx(a.y-b.y)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
