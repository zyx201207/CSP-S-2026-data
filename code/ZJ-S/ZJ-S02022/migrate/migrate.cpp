#include<bits/stdc++.h>
#define int unsigned long long
#define N 2000010
using namespace std;
int n,d;
int c,t,cnt[N];
int a[N],b[N];
void fun1(int x,int l){
	if(l==b[x]){
		cnt[x]++;
	}
	else if(l<b[x]||b[x]==1){
		if(l<b[x]){
			cnt[x]=1;
		}
		b[x]=l;
	}
	if(x==n){
		return;
	}
	for(int i=1;i<=n-x;i++){
		if(a[x+i]-a[x]<=d){
			fun1(x+i,l+1);
		}
		else{
			return ;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n-d;i++){
			memset(cnt,1,sizeof cnt);
			memset(b,1,sizeof b);
			fun1(i,0);
			for(int i=1;i<=n;i++){
				if(cnt[i]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}