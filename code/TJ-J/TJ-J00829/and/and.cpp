#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int maxn=0,ans=0,n,m;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum==a[i] and a[i+1];
		maxn=max(sum,maxn);
	}
	cout<<maxn;
	return 0;
}
