#include<bits/stdc++.h>
using namespace std;
int a[200005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);	
		cout<<ans;
	}
	else if(n==m-1){
		int temp=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				temp=temp&a[j];
			}
			ans=max(ans,temp);
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
	}
	else if(m==1) cout<<maxn;
	else if(maxn<=4) cout<<3;
	else{
		sort(a+1,a+n+1);
		cout<<a[n+1-m];
	}
	return 0;
}
