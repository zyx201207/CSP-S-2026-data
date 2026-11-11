#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
bool if_a;
int ans[100002];
int now[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) if_a=1;
	}
	if(!if_a){
		a[n+1]=-1;
		for(int i=1;i<=n+1;i++){
			if(a[i]!=a[i-1]) ans[a[i-1]]=i-1;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	}else{
		for(int i=1;i<=n;i++){
			memset(now,0,sizeof(now));
			int pos=0;
			for(int j=i;j<=n;j++){
				int if_have=0;
				for(int k=1;k<=pos;k++){
					if(now[k]==a[j]){
						if_have=k;
						break;
					}
				}
				if(if_have!=0) pos=if_have;
				else now[++pos]=a[j];
			}
			for(int j=1;j<=pos;j++){
				ans[now[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	}
	return 0;
}
