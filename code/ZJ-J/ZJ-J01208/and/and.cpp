#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,K=35;
long long lg[K];
long long n,m;
long long a[N];
long long maxn=0;
void dfs(long long now,long long num,long long sum){
	if (num>m || n-now+num<m)return;
	if (num==m){
		maxn=max(maxn,sum);
		return ;
	}
	if (now>=n){
		maxn=max(maxn,sum);
		return ;
	}
	if (num!=0){
		dfs(now+1,num+1,sum&a[now+1]);
	}
	else {
		dfs(now+1,num+1,a[now+1]);
	}
	dfs(now+1,num,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	lg[0]=0;
	for (int i=1;i<=30;i++){
		lg[i]=lg[i-1]*2;
	}
	int flag=1,blok=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]>=4)blok=0;
		int blog=0;
		for (int j=0;j<=30;j++){
			if (a[i]==lg[j]){
				blog=1;
				break;
			}
		}
		if (!blog){
			flag=0;
		}
	}
	if (flag){
		sort(a+1,a+n+1);
		long long ans=a[n];
		for (int j=n-1;j>=n-m+1;j--){
			ans &= a[j];
		}
		cout<<ans<<endl;
		return 0;
	} 
	if (blok){
		long long sum=0;
		for (int j=1;j<=n;j++){
			if (a[j]>=3){
				sum++;
			}
		}
		if (sum>=m){
			cout<<3<<endl;
			return 0;
		}
		sum=0;
		for (int j=1;j<=n;j++){
			if (a[j]>=2){
				sum++;
			}
		}
		if (sum>=m){
			cout<<2<<endl;
			return 0;
		}
		sum=0;
		for (int j=1;j<=n;j++){
			if (a[j]==1 || a[j]==3){
				sum++;
			}
		}
		if (sum>=m){
			cout<<1<<endl;
			return 0;
		}		
		cout<<0<<endl;
		return 0;
	}
	dfs(0,0,0);
	cout<<maxn<<endl;
	return 0;
}
