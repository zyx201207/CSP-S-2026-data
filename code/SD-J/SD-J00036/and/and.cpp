#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
const int N=2e5+5;
int n,m,total,a[N],wai[N];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int step){
	if(step==m+1){
		int ans=2147483647;
		for(int i=1; i<=m; ++i){
			ans=ans&a[wai[i]];
		}
		total=max(total,ans);
		return;
	}
	for(int i=wai[step-1]+1; i<=n-m+step; ++i){
		wai[step]=i;
		dfs(step+1);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		total=-1;
		for(int i=1; i<=n; ++i){
			cin>>a[i];
			total=max(total,a[i]);
		}
		cout<<total<<'\n';
		return 0;
	} else if(m==2){
		total=-1;
		for(int i=1; i<=n; ++i){
			cin>>a[i];
			for(int j=1; j<i; ++j){
				total=max(total,a[i]&a[j]);
			}
		}
		cout<<total<<'\n';
		return 0;
	} else if(m==n){
		total=2147483647;
		for(int i=1; i<=n; ++i){
			cin>>a[i];
			total=total&a[i];
		}
		cout<<total<<'\n';
		return 0;
	} else if(m==n-1){
		total=-1;
		int pre_sum[N], last_sum[N];
		pre_sum[0]=last_sum[n+1]=2147483647;
		for(int i=1; i<=n; ++i){
			cin>>a[i];
			pre_sum[i]=pre_sum[i-1]&a[i];
		}
		for(int i=n; i>=1; --i){
			last_sum[i]=last_sum[i+1]&a[i];
		}
		for(int i=1; i<=n; ++i){
			total=max(total,pre_sum[i-1]&last_sum[i+1]);
		}
		cout<<total<<'\n';
		return 0;
	}
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
		cout<<total<<'\n';
		return 0;
	}
	sort(a+1, a+n+1,cmp);
	total=2147483647;
	for(int i=1; i<=m; ++i){
		total=total&a[i];
	}
	cout<<total<<'\n';
	return 0;
}
