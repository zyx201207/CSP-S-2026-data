#include<bits/stdc++.h>
using namespace std;
int main(){	

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[2005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
	
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans and a[i];
		}
		cout<<ans;
	}
	 else if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}

		cout<<mx;
	}
	else if(m==2){
		cout<<1111;
		int ans=a[1],ans2=0;
		for(int i=2;i<=n;i++){
			ans2=ans;
			ans=ans and a[i];
		}
		sort(a+1,a+1+n);
		cout<<ans and a[n-1];
	}
	return 0;
}
