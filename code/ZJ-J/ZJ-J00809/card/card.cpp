#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll cnt;
ll a[500050];
ll b[500050];
ll ans[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			bool flag=1;
			for(int x=1;x<=cnt;x++){
				if(b[x]==a[j]){
					cnt=x;
					flag=0;
					break;
				}
			}
			if(flag){
				b[++cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}