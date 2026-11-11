#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn=2e5+10;
ll n,m,a[maxn],res,flag=1,cnt[5],flaga=1,flagb=1;
bool used[30];
void dfs(ll ans,int step,int chose){
	if(step==n+1||chose==m){
		if(step==n+1&&chose==m)res=max(ans,res);
		return;
	}
	dfs(ans,step+1,chose);
	if(!used[step]){
		used[step]=1;
		dfs(ans&a[step],step+1,chose+1);
		used[step]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4)flag=0;
		else cnt[a[i]]++;
		if(log2(a[i]+1)!=(int)log2(a[i]+1))flaga=0;
		if(a[i]!=i-1)flagb=0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			used[i]=1;
			dfs(a[i],1,1);
			used[i]=0;
		}
		cout<<res;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)res=max(res,a[i]);
		cout<<res;
		return 0;
	}
	if(m==n){
		res=a[1];
		for(int i=2;i<=n;i++)res=res&a[i];
		cout<<res;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				res=max(res,a[i]&a[j]);
			}
		}
		cout<<res;
		return 0;
	}
	if(flaga||flagb){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(flag){
		if(cnt[4]>=m)res=4;
		else if(cnt[3]>=m)res=3;
		else if(cnt[2]+cnt[3]>=m)res=2;
		else if(cnt[1]+cnt[3]>=m)res=1;
		else res=0;
		cout<<res;
		return 0;
	}
	if(m==n-1){
		int minn=0x3f3f3f3f,place=0;
		for(int i=1;i<=n;i++){
			if(__builtin_popcount(a[i])<minn){
				minn=__builtin_popcount(a[i]);
				place=i;
			}
		}
		if(place==1)res=a[2];
		else res=a[1];
		for(int i=1;i<=n;i++){
			if(place==i)continue;
			res=res&a[i];
		}
		cout<<res;
		return 0;
	}
	for(int i=1;i<=n;i++){
		used[i]=1;
		dfs(a[i],1,1);
		used[i]=0;
	}
	cout<<res;
	return 0;
}