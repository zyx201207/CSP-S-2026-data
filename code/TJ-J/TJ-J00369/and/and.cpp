#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],p[35],ans1,ans2,f=1;
void dfs(int i,int d,int x){
	if(d==m){
		ans1=max(ans1,x);
		return;
	}
	if(i==n+1)
		return;
	dfs(i+1,d+1,x&a[i]);
	dfs(i+1,d,x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=31;i++)
		p[i]=p[i-1]*2;
	ans2=p[31];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans2&=a[i];
		int f2=0;
		for(int j=1;j<=31;j++)
			if(a[i]==p[j]-1)
				f2=1;
		if(!f2)
			f=0;
	}
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0,a[n]);
		cout<<ans1;
		return 0;
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		cout<<ans2;
		return 0;
	}
	if(n<=2000&&m==2){
		int ans3=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&a[i]&a[j]>ans3)
					ans3=a[i]&a[j];
		cout<<ans3;
		return 0;
	}
	if(m==n-1){
		int ans4=0;
		for(int i=1;i<=n;i++)
			ans4=max(ans2^(p[31]^a[i]),ans4);
		cout<<ans4;
		return 0;
	}
	if(f){
		int ans5=p[31];
		for(int i=n;i>=n-m+1;i--)
			ans5&=a[i];
		cout<<ans5;
		return 0;
	}
	return 0;
}
