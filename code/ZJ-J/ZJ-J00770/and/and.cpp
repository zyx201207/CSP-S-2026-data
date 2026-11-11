#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[500001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	if(m==1)cout<<a[1];
	else if(sqrt(n)*sqrt(n)==n){
		int t=a[1];
		for(int i=2;i<=m;i++)t&=a[i];
		printf("%d",t);
	}
	else cout<<a[m];
	return 0;
}
