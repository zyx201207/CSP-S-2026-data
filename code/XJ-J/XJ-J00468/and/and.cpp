#include<bits/stdc++.h> 
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5;
int a[N];
int n,m,mx = 0,f = 0,themx = 0;
void dfs(int now,int cnt,int sum){
	if(themx==1){
		return;
	}
	if(cnt==m){
		mx = max(mx,sum);
		if(mx/2>a[now+1]/2){
			themx  =1;
			return;
		}
		return;
	}
	if(now>n){
		return;
	}
	dfs(now+1,cnt,sum);
	if(sum==0&&f==0){
		sum = a[now];
		f==1;
	}
	dfs(now+1,cnt+1,(sum&a[now]));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<mx;
	return 0;
}

