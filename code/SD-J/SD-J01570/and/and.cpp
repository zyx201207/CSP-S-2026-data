#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010];
bool cmp1(int i,int j){
	return i>j;
}
bool vis[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int jmc=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)jmc++;
	}
	if(jmc>n-m){
		cout<<0;
		return 0;
	}
	if(jmc==n-m){
		int ans;
		int k=1;
		while(1){
			if(a[k]!=0)break;
			k++;
		}
		for(int i=k;i<=n;i++)if(a[i]!=0)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp1);
	if(n==m){

		int ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}		
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
    return 0;
}

