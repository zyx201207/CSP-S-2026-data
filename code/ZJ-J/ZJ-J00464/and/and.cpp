#include<bits/stdc++.h>
using namespace std;
long long a[1000005],n,m,res[1000005],cnt,mx=-2e9;
long long _and(long long a,long long b){
	long long ans=0,cnt=0;
	while(a!=0&&b!=0){
		if(a%2==1&&b%2==1)ans+=pow(2,cnt);
		cnt++;
		a/=2,b/=2;
	}
	return ans;
}
void dfs(int l,int pre){
	if(l==m){
		long long ans=2147483647;
		for(int i=0;i<=m;i++){
			ans=_and(ans,res[i]);
		}
		mx=max(mx,ans);
	}
	if(pre>n)return ;
	for(int i=pre;i<=n;i++){
		res[l]=a[i];
		dfs(l+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int flagg=1,flag2=0,flagg2=1;
	cin>>n>>m;
	for(int i=1;i<=30;i++){
		if(pow(2,i)==n){
			flag2=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)flagg2=0;
		int flag=0;
		for(int j=1;j<=30;j++){
			if(a[i]==pow(2,i)-1){
				flag=1;
				break;
			}
		}
		if(flag==0)flagg=0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			long long ans=2147483647;
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				ans=_and(ans,a[j]);
			}
			mx=max(mx,ans);
		}
		cout<<mx;
		return 0;
	}
	if(flagg==1){
		sort(a+1,a+1+n,greater<int>());
		long long ans=2147483647;
		for(int i=1;i<=m;i++){
			ans=_and(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(flag2==1&&flagg2==1){
		sort(a+1,a+1+n,greater<int>());
		long long ans=2147483647;
		for(int i=1;i<=m;i++){
			ans=_and(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	dfs(0,1);
	cout<<mx;
	return 0;
}
