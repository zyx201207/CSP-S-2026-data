#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long s[500010];
long long val(int l,int r){
	int mid=(l+r)/2;
	long long x=a[r];
	long long ret=x*(r-l+1)-(s[r]-s[l-1]);
	return ret;
}
int main(){
	//system("fc crystal.out crystal3.ans");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int j=1,ans=1;
	for(int i=1;i<=n;i++){
		while(j+1<=n && val(i,j+1)<=m)j++;
		ans=max(ans,j-i+1);
	}
	cout << ans;
	return 0;
}
