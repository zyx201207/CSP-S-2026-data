#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200010],ans;
int bin[31];
queue<int>q;
void solve1(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans=max(ans,(a[i]&a[j]));
	cout<<ans;
	return;
}
void solve2(){
	ans=a[1];
	for(int i=2;i<=n;i++)ans=(ans&a[i]);
	cout<<ans;
	return;
}
void dfs(int x,int tot,long long int sum){
	if(tot==m){
		ans=max(ans,sum);
		return;
	}
	if(x>n)return;
	if(tot==0)dfs(x+1,tot+1,a[x]);
	else dfs(x+1,tot+1,(sum&a[x]));
	
	dfs(x+1,tot,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2&&n<=2000){
		solve1();
		return 0;
	}
	if(m==n){
		solve2();
		return 0;
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		int is=0;
		for(int j=0;j<31;j++)
			if(a[i]==pow(2,j)-1){
				is=1;
				break;
			}
		if(is==0){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<a[m];
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<31;j++)
			bin[j]+=((a[i]>>j)&1);
	if(m==n-1){
		int wz=-1;
		for(int i=0;i<31;i++)
			if(bin[i]==n-1){
				wz=i;
				break;
			}
		if(wz==-1)solve2();
		else{
			ans=pow(2,30)-1;
			for(int i=1;i<=n;i++){
				if((a[i]>>wz)&1==0)continue;
				ans=(ans&a[i]);
			}
			cout<<ans;
		}
		return 0;
	}
//	int wz=-1;
//	for(int i=0;i<31;i++)
//		if(bin[i]>=m){
//			wz=i;
//			break;
//		}
//	if(wz==-1){
//		cout<<0;
//		return 0;
//	}
//	for(int i=1;i<=n;i++)q.push(i);
	
	return 0;
}