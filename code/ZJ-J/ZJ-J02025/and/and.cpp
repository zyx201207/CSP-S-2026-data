#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200005],flag[25],n,mx;

void solve20(int m){
	int ans=2147483647;
	if(m==0){
		for(int i=1;i<=n;i++){
			if(flag[i])ans=ans&a[i];
		}
		mx=max(ans,mx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			solve20(m-1);
			flag[i]=0;
		}
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx<<endl;
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(n<=20){
		solve20(m);
		cout<<mx<<endl;
		return 0;
	}
	else{
		int mx0=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx0=max(mx0,a[i]&a[j]);
			}
		}
		cout<<mx0<<endl;
		return 0;
	}
}
