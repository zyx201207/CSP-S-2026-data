#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int mask=LLONG_MAX;
void fast_read(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
}
int n,m,a[N],ans,cnt[10]; 
void dfs(int st,int sum,int cnt){
	if(cnt>=m){
		ans=max(ans,sum);
		return;
	} 
	if(sum<ans)return;
	for(int i=st+1;i<=n;i++)
		dfs(i,sum&a[i],cnt+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fast_read();
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(0,mask,0);
		cout<<ans;
	} 
	else if(n<=2000){
		sort(a+1,a+n+1);
		if(m==1)cout<<a[n];
		else if(m==n){
			int sum=mask;
			for(int i=1;i<=n;i++)sum&=a[i];
			cout<<sum;
		}
		else{
			dfs(0,mask,0);
			cout<<ans;
		}
	}
	else{
		bool xingzhiA=1;
		for(int i=1;i<=n;i++)
			if(a[i]&(a[i]+1))xingzhiA=0;
		if(xingzhiA){
			sort(a+1,a+n+1,greater<int>());
			cout<<a[m];
		}
		else{
			for(int i=1;i<=n;i++)
				cnt[a[i]]++;
			if(cnt[4]>=m)cout<<4;
			else if(cnt[3]>=m)cout<<3;
			else if(cnt[2]+cnt[3]>=m)cout<<2;
			else if(cnt[1]+cnt[3]>=m)cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
