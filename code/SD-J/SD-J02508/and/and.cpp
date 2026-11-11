#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[200010],maxx=-1;
void dfs(int k,int sum,int ad){
	if(sum>=1&&ad<=maxx){
		return;
	}
	if(sum==m){
		maxx=max(maxx,ad);
		return;
	}else if(k>n&&sum<m){
		return;
	}
	if(sum==0){
		dfs(k+1,sum+1,a[k]);
		dfs(k+1,0,0);
	}else{
		dfs(k+1,sum+1,ad&a[k]);
		dfs(k+1,sum,ad);
	}
	return;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n]<<endl;
		return 0;
	}else if(m==n){
		int aaa=a[1];
		for(int i=2;i<=n;i++){
			aaa=aaa&a[i];
		}
		cout<<aaa<<endl;
		return 0;
	}else if(n<=20||m==2){
		dfs(1,0,0);
		cout<<maxx<<endl;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			int sum=-1;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(sum==-1){
					sum=a[j];
					continue;
				}
				sum=sum&a[j];
				if(sum<=maxx) break;
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx<<endl;
	}else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m]<<endl;
	}
	return 0;
}
