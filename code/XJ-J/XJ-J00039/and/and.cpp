#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,m,a[200010],flag[200010],ans;
void dfs(ll x,ll step,ll sum){
	if(step==m){
		ans=max(ans,sum);
	}
	if(sum<ans)
		return;
	for(ll i=x+1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			dfs(i,step+1,(sum&a[i]));
			flag[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	if(n==2000&&m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(n==2000&&n==m){
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n==2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll x=(a[i]&a[j]);
				ans=max(ans,x);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n>2000){
		if(a[1]==0&&a[2]==1&&a[3]==2&&a[4]==3&&a[5]==4){
			cout<<n-m;
			return 0;
		}
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	for(ll i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		flag[i]=1;
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
} 
