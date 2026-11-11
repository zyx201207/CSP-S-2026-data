#include<bits/stdc++.h>
using namespace std;
int const N=5*1e5+10,M=3*1e5+10;
int a[N],s[M]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	bool ba=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])ba=0;
	}
	if(ba){
		for(int i=1;i<=m;i++)cout<<i<<' ';
		return 0;
	}
	return 0;
}

