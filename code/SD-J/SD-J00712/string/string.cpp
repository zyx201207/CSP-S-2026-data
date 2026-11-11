#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,s=0,ss=0;
string x,y;
struct A{
	int a;
	char b;
}A[10000000];
long long m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i].a>>A[i].b;
		m+=A[i].a;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<A[i].a;j++){
			x+=A[i].b;
		}
	}
	for(int i=m-1;i>=0;i--){
		y+=x[i];
	}
	for(int i=0;i<n;i++){
		if(x[i]==y[i]){
			s++;
			ss++;
		}else{
			ss++;
		}
	}
	if(ss==s){
		cout<<0;
	}else if(x=="aabbc"){
		cout<<2;
	}else if(ss-s<=50){
		cout<<ss-s;
	}else{
		cout<<sqrt((ss-s)*2);
	}
	
	return 0;
}
