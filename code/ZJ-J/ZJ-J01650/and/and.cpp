#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],tmax;
bool st[N];
void dfs(int step,int sum){
	if(step>m){
		tmax=max(sum,tmax);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			st[i]=1;
			if(step==1)dfs(step+1,a[i]);
			else dfs(step+1,sum&a[i]);
			st[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(0,0);
		cout<<tmax;
	}
	else if(m==1){
		for(int i=1;i<=n;i++)tmax=max(tmax,a[i]);
		cout<<tmax;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)tmax=max(tmax,a[i]&a[j]);
		}
		cout<<tmax;
	}
	else if(n==m){
		int sum=a[1]&a[2];
		for(int i=3;i<=n;i++)sum=sum&a[i];
		cout<<sum;
	}
	return 0;
}
