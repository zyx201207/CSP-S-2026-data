#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int s=a[i];
		for(int j=0;j<i;j++){
			s^=abs(s-a[j]);
			long long max1=max(a[i],a[j]);
			ans=max(max1-s,ans);
		}
	}cout<<ans;
	return 0;
} 
