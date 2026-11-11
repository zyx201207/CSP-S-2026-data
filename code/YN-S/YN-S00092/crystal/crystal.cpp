#include<bits/stdc++.h>
using namespace std;

#define int long long

const int scx=5e5+10;
int n,m;
int a[scx];
int ans;
int sum;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<1;
		return 0;
	}
	int l=1,r=1,i=2;
	sum=a[1];
	while(i<n){
		if(a[i]*(r-l+1)-sum<=m){
			if(a[i+1]*(r-l+2)-sum-a[i]<=m){
				sum+=a[i];
				r++;
				i++;
				ans=max(ans,r-l+2);
			}else{
				ans=max(ans,r-l+2);
				if(l==r){
					sum=a[i];
					i++;
					l++;
					r++;
					continue;
				}
				sum-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
	
}
