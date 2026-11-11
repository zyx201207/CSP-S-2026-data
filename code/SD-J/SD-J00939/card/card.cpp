#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+2;
const int M=3e5+2;
bool vis[M];
int arr[N],num[N];
int fa[N],add[N];
int lst[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=n;i;i--)
		if(!lst[arr[i]]) lst[arr[i]]=i;
	for(int i=1;i<=n;i++) num[i]=1;
	for(int i=n;i;i--){
		if(!vis[arr[i]]){
			vis[arr[i]]=true;
			add[i]=arr[i];
			fa[i]=i+1;
		}
		else fa[i]=lst[arr[i]];
	}
	for(int i=1;i<=n;i++){
		if(add[i]) ans[add[i]]+=num[i];
		num[fa[i]]+=num[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

