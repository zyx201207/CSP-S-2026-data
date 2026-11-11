#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int v[30];
int dfs(int x,int len){
	if(x>n){
		if(len<m)return 0;
		int res=(1<<31)-1;
		for(int i=1;i<=len;i++)res=(res&v[i]);
		return res;
	}
	int ans=0;
	if(len<m)v[len+1]=a[x],ans=dfs(x+1,len+1);
	ans=max(ans,dfs(x+1,len));
	return ans;
}
int b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		cout<<dfs(1,0)<<endl;
		return 0;
	}
	else if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n]<<endl;
		return 0;
	}
	else if(m==2&&n<=1000){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		} 
		cout<<ans;
		return 0;
	}
	else if(m==n){
		long long cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=(cnt&a[i]);
		}
		cout<<cnt;
		return 0;
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i))cnt++;
		}
		if(cnt<m)continue;
		ans+=(1<<i);
		int len=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i)){
				b[++len]=a[j];
			}
		}
		n=len;
		for(int i=1;i<=len;i++)a[i]=b[i];
	}
	cout<<ans;
	return 0;
} 
//Trick||Treat!
