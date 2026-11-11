#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,n,max=0,b=0;
	int m[a+5]
	for (int i=0;i<a;i++){
		cin>>m[i];
	}
	for(int i=0;i<a+10;i++){
	if(m[i+1]>m[i]){
	max=m[i];
	m[i]=m[i+1];
	m[i+1]=max;
	}
	}
	b=m[0];
	for(int i=1;i<a;i++){
	b=b&m[i];
	}
	cout<<b;
	return 0;
}
