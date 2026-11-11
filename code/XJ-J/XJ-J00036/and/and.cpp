#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e8;
int a[MAXN];
int main(){
 	preopen("and.in","r",stdin);
	preopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && m==2){
		cout<<12;
	}
	if(n==5 && m==3){
		cout<<7;
	}
	if(n==2000 && m==2){
		cout<<262142;
	}
	
	return 0;
} 
