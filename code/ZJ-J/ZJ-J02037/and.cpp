#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009],b[200009],o[200009],tof[200009];
char c[200009][33],cc[200009][33],d[200009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	cout<<a[m];
	return 0;
}
