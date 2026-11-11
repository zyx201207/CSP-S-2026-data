#include<bits/stdc++.h>
using namespace std;
bool px(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,px);
	int t=0,k=a[1];
	for(int i=1;i<=m;i++){
		t=k&a[i];
		k=t;
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
