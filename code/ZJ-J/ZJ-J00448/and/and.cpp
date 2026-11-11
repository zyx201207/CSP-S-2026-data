#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int maxs=0;
void f(int now,int chose,int maxss){
	if(chose>m){
		return;
	}
	if(now==n+1 && chose!=m){
		return;
	}
	else if(now>n && chose==m){
		maxs=max(maxss,maxs);
		return;
	}
	else{
		if(chose==0){
			f(now+1,chose+1,a[now]);
			f(now+1,chose,maxss);
		}
		else{
			f(now+1,chose+1,min(maxss,a[now]));
			f(now+1,chose,maxss);
		}
		return;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,0,0);
	cout<<maxs;
	return 0;
}
