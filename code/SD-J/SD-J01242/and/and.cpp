#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[200005],maxn,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(i==1)ans=a[i];
		else ans=ans&a[i];
	}
	if(m==1){
		cout<<maxn<<endl;
	}else if(m==2){
		int ans1=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans1=max(ans1,a[i]&a[j]);
			}
		}
		cout<<ans1<<endl;
	}else if(m==n){
		cout<<ans<<endl;
	}else if(m==n-1){
		int ans2=0;
		for(int i=1;i<=n;i++){
			ans2=max(ans2,ans^a[i]);
		}
		cout<<ans2<<endl;
	}else{
		sort(a+1,a+1+n,greater<int>());
		int ans3=a[1];
		for(int i=2;i<=m;i++)ans3^=a[i];
		cout<<ans3<<endl;
	}
	return 0;
}

