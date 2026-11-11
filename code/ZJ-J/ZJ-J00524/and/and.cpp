#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
int n,m,ans,Max,sum;
int a[N],s[N][35],t[35];
void dfs(int dep,int choices,int s){
	if(choices==m){
		ans=max(ans,s);
		return;
	}
	if(dep>n)return;
	dfs(dep+1,choices,s);
	if(!choices)dfs(dep+1,choices+1,a[dep]);
	else dfs(dep+1,choices+1,s&a[dep]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("and3.in","r",stdin);
//	freopen("and3.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		Max=max(Max,a[i]);
		if(i==1)sum=a[1];
		else sum&=a[i];
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ans<<"\n";
	}//25
	else if(n<=2000){
		if(m==1)cout<<Max<<"\n";
		else if(m==n)cout<<sum<<"\n";
		else if(m==2){
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j){
					if(i==j)continue;
					ans=max(ans,a[i]&a[j]);
				}
			cout<<ans<<"\n";
		}
	}//25
	else if(m==n-1){
		int max_len=0;
		for(int i=1;i<=n;++i){
			int now=a[i],len=1;
			while(now){
				s[i][len]=(now&1);
				t[len]+=(now&1);
				now>>=1;
				++len;
			}
			max_len=max(max_len,len);
		}
		for(int i=1;i<=n;++i){
			int sum=0,len=1,now=a[i];
			while(now){
				int and_s=now&1;
				if(t[len]-and_s==n-1)sum+=(int)pow(2,len);
				now>>=1;
				++len;
			}
			for(int i=len;i<=max_len;++i)
				if(t[i]==n-1)sum+=(int)pow(2,i);
			ans=max(ans,sum);
		}
		cout<<ans<<"\n";
	}//maybe 10??
	
	return 0;
}
/*
使用得当可以骗到85-95
但我只能拿60
*/