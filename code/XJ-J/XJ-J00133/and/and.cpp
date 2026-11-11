#include <bits/stdc++.h>
using namespace std;
long long a[200009];
long long x[200009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	int n,m;
	int cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		a[i]=x[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	if(m==2){
		cout<<(a[1]&a[2]);
	}
	if(m==1){
		cout<<a[1];
	}
	
	return 0;
}
