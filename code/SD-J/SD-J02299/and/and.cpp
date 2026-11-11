#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define x1 x_1
#define x2 x_2
#define y1 y_1
#define y2 y_2
using namespace std;

long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
int ans=0;
int n,m;
int a[200005];
void dfs(int i,int k,int sum){
	if(k==0) ans=max(ans,sum);
	if(k==0||i>n) return;
	dfs(i+1,k-1,sum&a[i]);
	dfs(i+1,k,sum);
}
int main(){
	//一定一定要记得初始化！！！！！
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
    	a[i]=read();
	}
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(n>=50){
		sort(a+1,a+n+1);
		int ans=(1<<30)-1;
		for(int i=n;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
	}
	else {
		dfs(1,m,(1<<31)-1);
	cout<<ans;
	}
	return 0;
}

