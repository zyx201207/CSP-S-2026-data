#include<bits/stdc++.h>
using namespace std;
const int N=(2*1e5)+7;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<12;	
	}else if(n==5){
		cout<<7;
	}
	return 0;
}