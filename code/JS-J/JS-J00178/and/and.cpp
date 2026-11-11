#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans=-1;
int b[N];
bool f[N];
bool A_shu(int x){
	int p=log2(x+1);
	int cal=pow(2,p)-1;
	return cal==x;
}
void dfs(int k){
	if(k==m+1){
		int num=a[b[1]];
		for(int i=1,x;i<k;i++){
			x=b[i];
			num=num&a[x];
		}
		ans=max(ans,num);
		return;
	}
	for(int i=k;i<=n;i++){
		if(!f[i]){
			f[i]=1,b[k]=i;
			dfs(k+1);
			f[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans<<endl;
	}
	else if(m==2){
		int ans=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
	}
	else if(m==n-1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			int num=-1;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(num==-1) num=a[j];
				num=num&a[j];
			}
			ans=max(ans,num);
		}
		cout<<ans<<endl;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++) ans=ans&a[i];
		cout<<ans<<endl;
	}
	else{
		sort(a+1,a+1+n);
		bool A=1,B=1,C=1;
		if(!A_shu(n-1)) B=0;
		for(int i=1;i<=n;i++){
			if(!A_shu(a[i])) A=0;
			if(a[i]!=i-1) B=0;
			if(a[i]>=4) C=0;
		}
		//cout<<A<<" "<<B<<" "<<C<<endl;
		if(A||B||C||n>20){
			sort(a+1,a+1+n,greater<int>());
			int ans=a[1];
			for(int i=1;i<=m;i++) ans=ans&a[i];
			cout<<ans;
		}
		else{
			dfs(1);
			cout<<ans;
		}
	}
	return 0;
}
