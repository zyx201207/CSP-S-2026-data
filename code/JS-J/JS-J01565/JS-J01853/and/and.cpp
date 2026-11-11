#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];
int ans=LLONG_MIN;
void dfs(int cnt,int idx,int andd){
	if(andd<ans)return;
	if(cnt==m){
		ans=max(ans,andd);
		return;
	}
	for(int i=idx+1;i<=n-m+cnt+1;i++){
		dfs(cnt+1,i,andd&a[i]);
	}
	return;
}
bool judge(int k){
k++;
	while(k){
		if(k%2&&k>1)return 0;
		k/=2;
	}
return 1;
}
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool isa=1,isb=1;
	for(int i=1;i<=n;i++)cin>>a[i],isa=isa&&judge(a[i]);
	for(int i=1;i<=n;i++)isb=isb&&(a[i]<=4);
	if(isb){
		int cnt[10];
		cnt[0]=cnt[1]=cnt[2]=cnt[3]=cnt[4]=0;
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		if(cnt[3]>=m)cout<<3;
		else if(cnt[2]+cnt[3]>=m)cout<<2;
		else if(cnt[1]+cnt[3]>=m)cout<<1;
		else cout<<0;
		cout<<'\n';return 0;
}
	if(isa){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m]<<'\n';
		return 0;
	}
	//sort(a+1,a+n+1,greater<int>());
	if(m==1){
		int maxx=LLONG_MIN;
		for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
		cout<<maxx<<'\n';
		return 0;
	}
	if(m==n){
		int maxx=(1<<30)-1;
                for(int i=1;i<=n;i++)maxx&=a[i];
                cout<<maxx<<'\n';
		return 0;
}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	dfs(0,0,(1<<30)-1);
	cout<<ans<<'\n';
	return 0;
}
