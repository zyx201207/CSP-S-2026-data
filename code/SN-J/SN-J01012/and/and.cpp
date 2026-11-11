#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	//freopen("and.in ","r",stdin);
	//freopen("and.out","w",stdin);
	int n,m,mx=0;
	cin>>n>>m;
	cout<<log(3);
	int a[200010];
	bool x=1,y=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(log(a[i]+1)<ceil(log(a[i]+1))) x=0;
		if(log(a[i])<ceil(log(a[i]))) y=0;
		mx=max(mx,a[i]);
		
	}
	sort(a+1,a+n+1,cmp);
	if(m=1){
		cout<<a[1];
		return 0;
	}
	if(x){
		cout<<a[1];
		return 0;
	}
	if(y){
		cout<<a[m];
		return 0;
	}
	if(mx<=4){
		cout<<4;
		return 0;
	}
	if(m=2){
		cout<<a[2];
		return 0;
	}
	cout<<0;
	return 0;
}
