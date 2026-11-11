#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200200];
int ans[200200];
int cmp(int x,int y){
	return x>y;
}
int boool(int x,int y){
	if(x&y==y)return 1;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	int maxx=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<+n;j++){
				if(i!=j){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		}
		cout<<maxx;
		return 0 ;
	}
	if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx&=a[i];
		}
		cout<<maxx;
		return 0;
	}
	bool qwe=true;
	for(int i=2;i<=n;i++){
		if(!boool(a[i],a[i-1]))qwe=false;
	}
	if(qwe){
		cout<<a[m];
		return 0;
	}
	return 0;
}
