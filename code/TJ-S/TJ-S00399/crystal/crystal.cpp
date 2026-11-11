#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,out=0;
	int a[n]={};
	for( ; ; ){
		if(a[1]<a[3]){
			a[1]++;
			m--;
		}
		if(m==0){
			break;
		}
		if(a[2]<a[3]){
			a[2]++;
			m--;
		}
		if(m==0){
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[3])
		out++;
	}
	return 0;
}
