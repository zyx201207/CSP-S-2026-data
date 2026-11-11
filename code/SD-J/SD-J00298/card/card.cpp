#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500500];
int ans[300300];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool boool=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])boool=false;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
			if(a[n]!=a[i])ans[a[n]]++;
		}
		cout<<ans[1]<<' '<<ans[2];
		return 0;
	}
	if(boool){
		int tot=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]!=tot){
				cout<<i-1<<' ';
				tot=a[i];
			}
		}
		cout<<n;
		return 0;
	}
	return 0;
}
