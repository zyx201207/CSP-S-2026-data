#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[n+5];
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	if(m=1){
		cout<<a[0];
	}
	return 0;
}
