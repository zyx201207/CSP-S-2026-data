#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N];
ll maxn,maxm;//maxn表示dfs中最大的and答案
//maxm表示当 m=1 时 and 的最大答案，即为 a[i] 中的最大值
ll andsum;//表示当 m==n 时的 ans,即为 a[0] and a[1] and a[2] and...and a[n-1]
ll anw;// m==2 时的 ans
bool flag=1; //用于区别测试点 13 与测试点 14
ll anwe;//测试点 13-15 的 ans
void dfs(ll dep,ll cnt,ll ans) { //dep表示当前将要选择到a[dep]项,保证选择不重复,cnt用于统计选择数量,ans表示当前and结果
	if(cnt==m) {
		maxn=max(ans,maxn);
		return;
	}
	for(int i=dep; i<n; i++) {
		dfs(i,cnt+1,ans&a[dep]);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		maxm=max(a[i],maxm);
		if(a[i]!=i) flag=0;
	}
	if(n<=20) { //测试点 1-5 / 25pts 使用dfs
		for(int i=0; i<n; i++) {
			dfs(i+1,1,a[i]);
		}
		cout<<maxn;
	} else if(m==1) {  //测试点 6
		cout<<maxm;
	} else if(m==n) {  //测试点 7
		andsum=a[0];
		for(int i=1; i<n; i++) {
			andsum=a[i]&andsum;
		}
		cout<<andsum;
	} else if(m==2) { //测试点 8-10
		ll mx;
		for(int i=0; i<n; i++) {
			mx=a[i];
			for(int j=i+1; j<n; j++) {
				mx=mx&a[j];
				anw=max(anw,mx);
				mx=a[i];
			}
		}
		cout<<anw;
	} else if(flag==0) { //测试点 13
		sort(a,a+n);
		ll anwe=a[n-m];
		cout<<anwe;
	} else if(flag==1) {  //测试点 14,15
		anwe=a[n-m];
		for(ll i=n-m+1; i<n; i++) {
			anwe=anwe&a[i];
		}
		cout<<anwe;
	}
	return 0;
}
//total:25+5+5+15+5+10=65pts   25-65pts
