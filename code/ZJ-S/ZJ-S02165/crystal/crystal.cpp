#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int ans;
long long c[500010];
bool cmd(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmd);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	for(int j=1;j<=n;j++){
		int l=j,r=n,mid=(j+n)/2;
		while(l<r){
			mid=ceil((l+r)/2.0);
			if(-c[mid]+c[j]+(mid-j)*a[j]<=m){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		if(c[l]-c[j]-(l-j)*a[j]>m){
				l--;
			}
		ans=max(ans,l-j+1);
	}
	cout<<ans;
}
