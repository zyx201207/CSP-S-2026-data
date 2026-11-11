#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010],s[500010];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		bool f=0;
		for(int i=1;i+mid-1<=n;i++){
			if(a[i+mid-1]*mid-(s[i+mid-1]-s[i-1])<=m){
				f=1;
				break;
			}
		}
		if(f==1){
			l=mid+1;
			ans=max(ans,mid);
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
