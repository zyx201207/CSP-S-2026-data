#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m,a[N],ans;
bool vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>{});
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(((a[i]>>k)&1)&&!vis[i])cnt++;
		if(cnt<m)ans*=2;
		else{
			for(int i=1;i<=n;i++)
				if(!((a[i]>>k)&1))vis[i]=1;
			ans=ans*2+1;
		}
	}cout<<ans<<endl;
}//T3<T2
//Ã»±Á×¡ 
