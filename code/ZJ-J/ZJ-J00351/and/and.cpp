#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[200005];
bool b[200005];
void dfs(int sum,int ans1) {
	if(sum==m+1) {
		ans=max(ans,ans1);
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(sum==1) {
			ans1=a[i];
			b[i]=1;
			dfs(sum+1,ans1&a[i]);
			b[i]=0;
		} else if(b[i]==0) {
			b[i]=1;
			dfs(sum+1,ans1&a[i]);
			b[i]=0;
		}
	}
	return ;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<=4) {
		if(m>4) cout<<0;
		else {
			sort(a+1,a+n+1);
			for(int i=n;i>=n-m+1;i--) a[n]=(a[n]&a[i]);
			cout<<a[n];
		}
	} else if(m==1) {
		for(int i=1; i<=n; i++) ans=max(a[i],ans);
		cout<<ans;
	} else if(m==2&&n*n<=100000000) {
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				ans=max(a[i]&a[j],ans);
		cout<<ans;
	} else if(m==n) {
		for(int i=1; i<=n; i++) a[1]&=a[i];
		cout<<a[1];
	} else if(n<=20) {
		dfs(1,0);
		cout<<ans;
	} else  {
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
/*
3 :0011
15:1111
12:1100

7 :00111
15:01111
31:11111
All true


5 3
31 3 1 15 7
*/
/*
嵊州市新城实验学校909，ZHY LOVE ZZQ  
我的洛谷:yeweibo 
*/ 

