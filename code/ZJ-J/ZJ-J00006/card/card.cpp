#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],lst[maxn];
int vis[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		vis[i]++;
		if(lst[a[i]]==i){
			vis[i+1]+=vis[i];
		}else{
			vis[lst[a[i]]]+=vis[i];
		}
	}
	for(int i=1;i<=m;i++)cout<<vis[lst[i]]<<" ";
	cout<<"\n";
}
