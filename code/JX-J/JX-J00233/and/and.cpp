#include <bits/stdc++.h>
using namespace std;
//zcy
int n,m;
int a[200010];
int ans;
void dfs(int cs,int num,int sum){
	if(cs==m) {ans=max(ans,sum);return;}
	for(int i=num+1;i<=n-m+1+cs;i++){
		int cnt=sum;
		cnt&=a[i];
		dfs(cs+1,i,cnt);
		}
	return ;
	}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)
	cin>>a[i];
if(m==n){
	int sum=a[1];
	for(int i=2;i<=n;i++){
		sum&=a[i];
		}
	cout<<sum;
	return 0;
	}
if(m==1){
	int sum=0;
	for(int i=1;i<=n;i++)
		sum=max(a[i],sum);
	cout<<sum;
	return 0;
	}
if(m==2){
	int sum=0;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			sum=max(sum,a[i]&a[j]);
	cout<<sum;
	return 0;
	}
for(int i=1;i<=n-m+1;i++){
	dfs(1,i,a[i]);
	}	
cout<<ans;
return 0;
}
//1001 1000 1110 1011
