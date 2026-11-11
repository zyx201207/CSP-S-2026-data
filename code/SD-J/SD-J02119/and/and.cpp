#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-m+1;i++){
		long long ans=a[i];
		for(int j=0;j<m;j++){
			ans=ans&a[i+j];
		}
		maxx=max(maxx,ans); 
	}
	cout<<maxx;
	return 0;
}
