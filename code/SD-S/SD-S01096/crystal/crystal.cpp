#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
long long a[N],qz[N];
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qz[i]=(a[i]-a[i-1])*(i-1)+qz[i-1];
	}
	for(int l=1,r=1;l<=r;){
		if(r<n)r++;
		else l++;
		if(qz[r]-qz[l]-(l-1)*(a[r]-a[l])<=m)ans=max(r-l+1,ans);
		else{
			while(qz[r]-qz[l]-(l-1)*(a[r]-a[l])>=m){
				l++;
			}
			ans=max(r-l+1,ans);
		}
	}
	cout<<ans;
	return 0;
} 
