#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				long long cnt=a[i]&a[j];
				ans=max(ans,cnt);
			}
		} 
		cout<<ans;
	}else{
		cout<<a[n-m+1];
	}
	return 0;
}
