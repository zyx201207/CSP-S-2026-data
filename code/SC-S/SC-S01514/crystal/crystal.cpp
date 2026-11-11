#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,m,ans=0;
	bool Speacial_Tasks_A_and_B=true;
	cin>>n>>m;
	vector<int> a;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
		if(i>=3&&a[i-1]-a[i-2]!=a[i-2]-a[i-3])	Speacial_Tasks_A_and_B=false;
	}
	if(Speacial_Tasks_A_and_B){	// 30tps
		int p=a[1]-a[0];
		cout<<min(n,m/p+1);
		return ;
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		int l=i,r=i,cnt=0;
		while(l>0&&cnt<=m){
			if(l>0)	l--;
			else break;
			if(cnt+a[i]-a[l]<=m)	cnt+=a[i]-a[l];
			else{
				l++;
				break;
			}
		}
		ans=max(ans,r-l+1);
		while(l<=i&&r<n&&l<r){
			cnt-=a[i]-a[l];
			l++;
			while(r<n&&cnt<=m&&l<r){
				if(r<n-1)	r++;
				else break;
				if(cnt+a[r]-a[i]<=m)	cnt+=a[r]-a[i];
				else{
					r--;
					break;
				}
			}
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	solve();
	
	return 0;
}
