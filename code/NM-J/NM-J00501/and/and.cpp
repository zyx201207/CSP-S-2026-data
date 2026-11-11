#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxf=-1;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n+1-m;i++){
		long long x=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			x&=a[j];
		}
		maxf=max(maxf,x);
	}
	cout<<maxf;
	return 0;
}
