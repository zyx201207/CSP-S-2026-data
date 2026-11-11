#include<cstdio>
#include<iostream>
using namespace std;
int v[10000];
int y=0;
int jt(int qq,int ww,int j,int rr){
	if(rr==qq){
		v[y]=j;
		y++;
		
	}
	else if(rr>qq){
		return 0;
	}
	for(int i=1;i<=ww;i++){
		jt(qq,ww,j+1,rr+i);
	}
	return 0;
}
int main(){
	freopen(" crystal.in","r",stdin);
	freopen(" crystal.ans","w",stdout);
	int a=0,b;
	cin>>a>>b;
	int d,l,o=0;
	int n=0;
	int c[1005];
	for(int i=0;i<b;i++){
		cin>>d>>l;
		for(int j=0;j<a;j++){
			cin>>c[i];
		}
		jt(d,l,n,o);
		d=0;
		l=0;
		o=0;
		n=0;
	}
	for(int i=0;i<y;i++){
		cout<<v[i];
	}
	return 0;
}
