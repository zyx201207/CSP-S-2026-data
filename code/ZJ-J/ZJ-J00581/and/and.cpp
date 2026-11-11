#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],vis[N];
bool cmp(int x,int y){
	return x>y;
}
int z=0,ans[30];
int n,m;
void dfs(int now){
	if(now==m+1){
		int nowz=(ans[1]&ans[2]);
		for(int i=3;i<=m;i++){
			nowz&=ans[i];
		}
		z=max(z,nowz);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			ans[now]=a[i];
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int x=pow(2,30)-1;
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx<<endl;
		return 0;
	}
	if(n<=2000&&m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx<<endl;
		return 0;
	}
	if(n<=20){
		dfs(0);
		cout<<z<<endl;
		return 0;
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if((x&a[i])==a[i]&&s<m){
			x&=a[i];
			s++;
		}
	}
	cout<<x;
	return 0;
}