#include<bits/stdc++.h>
using namespace std;
int a[100005],s[1000005],s1[1000005];
int andys(int x,int y){
	int r=0;
	int t=1;
	while(x!=0){
		s[t++]=x%2;
		x/=2;
	}
	int t1=1;
	while(y!=0){
		s1[t1++]=y%2;
		y/=2;
	}
	int u=1;
	
	for(int i=1;i<=min(t,t1)-1;i--){
		if(s[i]==s1[i]){
			r+=u;
		}
		u*=2;
	}
	return r;
}
int main(){
	
	
	
	cout<<andys(31,15);
			
	
	
	
	return 0;
}