#include<bits/stdc++.h>
using namespace std;
int n,m,p,q; 
char cn[3],cm[4],cp[3],cq[4],s,t;
bool check1(char x,char y){
	if(x<='C'&&y<='C')	return 1;
	if(x>='D'&&y>='D')	return 1;
	return 0;
}
bool check2(char x,char y){
	if(x=='D'||y=='D')	return 1;
	if(x=='B'||y=='B')	return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cn>>cm>>cp>>cq;
	n = (int)(cn[0]-'0')*10+(int)(cn[1]-'0');
	p = (int)(cp[0]-'0')*10+(int)(cp[1]-'0');
	if(n==p)	cout<<"1";
	else{
		cout<<"0000\n";
		return 0;
	}
	m = (int)(cm[0]-'0')*10+(int)(cm[1]-'0');
	q = (int)(cq[0]-'0')*10+(int)(cq[1]-'0');
	if(m==q)	cout<<"1";
	else{
		cout<<"000\n";
		return 0;
	}
	s = cm[2];
	t = cq[2];
	if(check1(s,t))	cout<<"1";
	else{
		cout<<"00\n";
		return 0;
	}
	if(check2(s,t))	cout<<"1";
	else{
		cout<<"0\n";
		return 0;
	}
	printf("\n"); 
	
	return 0;
} 
