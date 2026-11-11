#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans,maxn=-2;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-m+1;i++){
		ans=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			ans&=a[j];
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
