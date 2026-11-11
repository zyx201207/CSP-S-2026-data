#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[500005],d[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++) s[i]=s[i-1]+d[i];
	int ans=1,l=1,r=1;
	long long sum=d[1];
	while(r<=n-1){
		while(sum<=m){
			ans=max(ans,r-l+2);
			if(r==n-1) break;
			r++;
			sum+=d[r]*(r-l+1);
		}
		while(sum>m || l<r){
			sum-=d[l];
			l++;
			sum-=s[r]-s[l-1];
		}
		if(sum>m){
			l++;
			r++;
			sum=d[l];
		}
		else{
			r++;
			sum+=d[r]*(r-l+1);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
