#include<bits/stdc++.h>
using namespace std;
bool s(int a,int b){
	return a>b;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int g,h[n],v[n];
	cin>>n>>m;
	long long e,f=0;
	for(int i=0;i<n;i++){
		cin>>g;
		h[i]=g;
	}
	sort(h+0,h+n+1,s);
	for(int i=0;i<m;i++){
	//	cout<<"H[I]: "<<h[i]<<"       ";
		v[i]=h[i];
	}
	cout<<v[m-1];
	
}
