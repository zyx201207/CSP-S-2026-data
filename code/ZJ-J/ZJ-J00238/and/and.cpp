#include<bits/stdc++.h>
using namespace std;
long long a[200005],pow2[40];
int main(){
	ios::sync_with_stdio();
	cin.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long now=1;
	for(int i=0;i<=35;i++){
		pow2[i]=now;
		now=now*2;
	}
	int n,m;
	cin>>n>>m;
	if(m==1){
		int x,mx=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			mx=max(x,mx);
		}
		cout<<mx;
		return 0;
	}
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		bool flag=false;
		for(int i=1;i<=35;i++){
			if(pow2[i]>a[i]) break; 
			if(pow2[i]==a[i]){
				flag=true;
				break;
			}
		}
		if(!flag){
			flag1=false;
		}
		if(a[i]!=i-1){
			flag2=false;
		}
	}
	int k=-1;
	for(int i=1;i<=35;i++){
		if(pow2[i]>n) break;
		if(pow2[i]==n) k=i; 
	}
	flag2=flag2&&k;
	if(m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	if(flag1){
		int ans=a[n];
		for(int i=n-1,j=2;j<=m;i--,j++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	if(flag2){
		int x;
		for(int i=k;i>=0;i--){
			if(m<=pow2[k-i]){
				x=i;
				break;
			}
		}
		int ans=0;
		for(int i=k;x>0;x--,i--){
			ans+=pow2[i-1];
		}
		cout<<ans;
	}
	return 0;
}

