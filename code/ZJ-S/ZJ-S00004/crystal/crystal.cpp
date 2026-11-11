#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010],b[500010];
bool ch(int k){
	for(int i=k;i<=n;i++)
		while(a[i]*k-(b[i]-b[i-k])<=m)
			return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=1,r=n,M,s=0;
	while(l<=r){
		M=(r+l)/2;
		if(ch(M)) s=M,l=M+1;
		else r=M-1;
	}
	cout<<s;
 return 0;
}
