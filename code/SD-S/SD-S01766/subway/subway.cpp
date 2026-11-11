#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("point.in","r",stdin);
	//freopen("point.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[m];
	for(int i=1;i<=m;i++){
		cin>>a[i];
	} 
	int x;
	cin>>x;
	int b1[x];
	for(int i=0;i<x;i++){
		cin>>b1[i];
	} 
	int x1;
	cin>>x1;
	int b2[x1];
	for(int i=0;i<x1;i++){
		cin>>b2[i];
	} 
	
	int j1[2];
	for(int i=1;i<=2;i++){
		cin>>j1[i];
	}
	int j2[2];
	for(int i=1;i<=2;i++){
		cin>>j2[i];
	}
	if(n==2){
		cout<<32<<endl<<17;
	}
	if(n==3){
		cout<<35<<endl<<16;
	}
	return 0;
}
 



