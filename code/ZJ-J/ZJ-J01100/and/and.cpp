#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N];
int suml[N];
int ans=0;
void dfs(int x,int sum,int s){
	if(s<=ans&&ans!=0)return;
	if(x==n+1){
		if(sum==m){
			ans=max(ans,s);
		}
		return;
	}
	if(sum==m){
		ans=max(ans,s);
		return;
	}
	dfs(x+1,sum,s);
	if(sum==0)dfs(x+1,sum+1,a[x]);
	if(sum!=0)dfs(x+1,sum+1,s&a[x]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)suml[i]=a[i];
		else suml[i]=a[i]&suml[i-1];
		maxn=max(maxn,a[i]);
	}
	if(m==n){
		cout<<suml[n];
		return 0;
	}else if(m==1){
		cout<<maxn;
		return 0;
	}else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}else if(m==n-1){
		maxn=0;
		int sum=a[n];
		for(int i=n;i>=1;i--){
			if(i==n)maxn=max(maxn,suml[i-1]);
			else if(i==1)maxn=max(maxn,sum);
			else{
				maxn=max(maxn,suml[i-1]&sum);
			}
			sum&=a[i];
		}
		cout<<maxn;
		return 0;
	}else if(maxn<=4){
		int sum1=0,sum2=0,sum3=0,sum4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum1++;
			if(a[i]==2)sum2++;
			if(a[i]==3)sum3++;
			if(a[i]==4)sum4++;
		}
		if(sum4>=m){
			cout<<4;
		}else if(sum3>=m){
			cout<<3;
		}else if(sum2+sum3>=m){
			cout<<2;
		}else if(sum1+sum3>=m){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else{
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	return 0;
}
