#include<bits/stdc++.h>
using namespace std;
int a[2000009];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=-999;
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	else{
		sort(a+1,a+n+1,cmp);
		int yu=a[1];
		for(int i=2;i<=m;i++){
			yu&=a[i];
		}
		cout<<yu;
	}
	return 0;
}
