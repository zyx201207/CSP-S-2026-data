#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=5e5+10;
int n;
ll m,a[mxn],s[mxn],r,gc;
int ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=n;
	ll sum=0;
	for(int i=n;i>=1;i--){
		j=min(j,i);
		while(j>1&&sum+a[i]-a[j-1]<=m) {
			j--;
			sum+=a[i]-a[j];
		}
		//cout<<j<<" ";
		ans=max(ans,i-j+1);
		//cout<<sum<<" ";
		sum-=(i-j)*(a[i]-a[i-1]);
		//cout<<sum<<'\n';
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
