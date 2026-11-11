#include<bits/stdc++.h>
using namespace std;
int m,n,mun=1,f;
int a[100001]={};
void push(int i){
	a[mun++]=i;
}
void pop(){
	mun-=1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		push(c);
		bool b=false;
		for(int j=1;j<=mun-1;j++){
			if(a[j]==a[mun]){
				f=a[mun];
				for(int k=1;k<=mun-j;j++){
					pop();
				}
				push(f);
			}
		}
	}
	return 0;
} 
