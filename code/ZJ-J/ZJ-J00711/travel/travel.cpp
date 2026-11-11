#include<bits/stdc++.h>
using namespace std;
//#define int long long
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}
string r1,r2,x1,x2;
bool side(char x,char y){
	if((x<='C')&&(y<='C')||(x>'C')&&(y>'C')){
		return true;
	}
	return false;
}
bool near(char x,char y){
	if(abs(x-y)==1){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int x=0,y=0;
	for(int i=0;i<2;i++){
		x =x*10+r2[i]-'0';
	}for(int i=0;i<2;i++){
		y =y*10+x2[i]-'0';
	}
	if(r1==x1&&x==y){
		cout<<1;
	}else{
		cout<<0;
	}
	char numx=x2[2];
	char numy = r2[2];
	if(r1==x1&&x==y&&side(numx,numy)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(r1==x1&&x==y&&side(numx,numy)&&near(numx,numy)){
		cout<<1;
	}else{cout<<0;
	}
	
	return 0;
}
