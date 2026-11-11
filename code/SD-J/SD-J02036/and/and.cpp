#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int a[200005];
int ans[200005];
int maxx;
int h(int o,int m){
	int d=o;
	int sum=a[d];
	int sum1=a[d];
	for(int i=d+1;i<=d+m&&i<=n;i++){
		sum=(sum&a[i]);
	}
	for(int i=d;i>=d-m&&i>=1;i--){
		sum1=(sum&a[i]);
	}
	return max(sum,sum1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=h(i,m);
		maxx=max(maxx,t);
	}
	cout<<maxx;
	return 0;
}
