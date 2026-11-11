#include <bits/stdc++.h>
using namespace std;
long long x[30001];
char y[30001];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x[i]>>y[i];
		sum+=x[i];
	}
	long long mid=(sum+1)/2;
	sum=0;
	int l=1,r=n;
	while(sum<mid){
		if(x[l]==0) l++;
		if(x[r]==0) r--;
		if(y[l]==y[r]){
			if(l==r) break; 
			if(x[l]<=x[r]) {
				sum+=x[l];
				x[r]=x[r]-x[l];
				x[l]=0;
			}
			else {
				sum+=x[l];
				x[l]=x[l]-x[r];
				x[r]=0;
			}
		}
		if(y[l]!=y[r]){
			if(x[l]<=x[r]) {
				x[r]=x[r]-x[l];
				ans+=x[l];
				sum+=x[l];
				x[l]=0;
			}
			else {
				sum+=x[l];
				x[l]=x[l]-x[r];
				ans+=x[r];
				x[r]=0;
			}
		}
	}
	cout<<ans;
	
 } 
