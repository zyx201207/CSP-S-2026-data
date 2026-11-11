#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
ll m,a[500005],k;
bool f=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i==1) k=a[i]-a[i-1];
		else if(i>1&&a[i]-a[i-1]!=k) f=0;
	}
	if(f) {
		int i=1;
		while(k*i*(i+1)/2<m) i++;
		cout<<i;
		return 0;
	}
	for(int i=1; i<n; i++) {
		int sum=0,x=a[i],c=1;
		for(int j=i-1; j>=0; j--) {
			if(sum+a[j]>m) break;
			sum+=x-a[j],c++;
		}
		if(c>ans) ans=c;
	}
	cout<<ans;
	return 0;
}