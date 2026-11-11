#include<bits/stdc++.h>
using namespace std;
int dp[2010][30];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio();
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200010],maxa=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
