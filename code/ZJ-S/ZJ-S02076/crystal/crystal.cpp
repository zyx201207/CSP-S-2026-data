#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N],n,m,ans[N],l=1,r=2,cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		ans[i]=ans[i-1]+b[i]*i;
	}
	while(r<n){
		if(ans[r]<=m){
			ans[r+1]=ans[r]+b[r+1]*(r-l+2);
			r++;
		}
		else{
			ans[r]=ans[r]-(a[r+1]-a[l]);
			l++;
		}
		cnt=max(cnt,r-l+1);
		if(l==r&&ans[r]>m){
			l+=1;
			r+=1;
			ans[r]=b[r];
		}
	}
	cout<<cnt;
	return 0;
}
