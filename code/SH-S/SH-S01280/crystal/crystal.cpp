#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],pre[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0,pos=1;
	for(int i=1;i<=n;i++){
		while(pos<=i){
			int shu=pre[i]-pre[pos-1];
			int need=(i-pos+1)*a[i]-shu;
			if(need<=m){
				ans=max(ans,i-pos+1);break;
			}else{
				pos++;
			}
		}
	}
	cout<<ans;
}
