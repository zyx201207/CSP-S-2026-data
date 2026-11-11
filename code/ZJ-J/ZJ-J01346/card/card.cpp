#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500100];
int lst[300100];
int res[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	a[0]=0;
	cin>>n>>m;
	a[n+1]=0;
	int fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])fl=0;
	}
	if(fl==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1])cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int st=i;
		while(st<=n){
			res[a[st]]++;
			st=lst[a[st]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<res[i]<<" ";
	return 0;
} 
