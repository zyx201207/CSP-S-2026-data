#include <bits/stdc++.h>
using namespace std;
#define  fin(x)  freopen(x,"r",stdin)
#define  fout(x)  freopen(x,"w",stdout)
const int N=2e5;
int a[N];
bool f[N];
int n,m;
int jsbfb(int x){
	int sum=0,num=0;
	while (x){
		sum++;
		num+=x%2;
		x/=2;
	}
	return int(num*100.0/sum);
}
bool cmp(int a,int b){
	return a>b;
}
int dfsans=0;
void dfs(int bs,int sum){
	
	if (sum==m){
		int ans=(1<<31)-1;
		for (int i=1;i<=n;i++){
			if (f[i]){
				ans&=a[i];
			}
		}
		dfsans=max(dfsans,ans);
		
		return ;
	}
	if(bs>n) return ;
	dfs(bs+1,sum);
	f[bs]=true;
	dfs(bs+1,sum+1);
	f[bs]=false;
}
int main()
{
	fin("and.in");
	fout("and.out");
	cin>>n>>m;
	bool flag=true;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (jsbfb(a[i])!=100) flag=false;
	}
	if (m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if (m==n){
		int ans=(1<<31)-1;
		for (int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if (m==2){
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (j==i) continue;
				ans=max(ans,a[j]&a[i]);
			}
		}
		cout<<ans;
		return 0;
	}
	if (flag){
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	if (a[1]<4){
		cout<<a[m];
		return 0;
	}
	dfs(1,0);
	cout<<dfsans;
	return 0;
}
//pfdm
