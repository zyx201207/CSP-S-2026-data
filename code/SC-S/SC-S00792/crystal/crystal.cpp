#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1;
	long long m;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int idx=2;
	while(m&&idx<=n){
		for(int i=1;i<idx;i++){
			if(m>=a[idx]-a[i]) m-=a[idx]-a[i],a[i]=a[idx];
			else m=0;
		}
		int cnt=0;
		for(int i=1;i<=n&&a[i]==a[idx];i++){
			cnt++;
		}
		ans=max(cnt,ans);
		idx++;
	}
	cout<<ans;
	return 0;
}