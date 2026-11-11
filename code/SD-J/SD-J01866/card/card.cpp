#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int b[N];
int vis[N];
int q[N];
int top;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(vis[a[j]]!=0){
				vis[q[top]]=0;
				top--;
			}
			top++;
			q[top]=a[j];
			vis[a[j]]=1;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				b[a[j]]++;
				top--;
				vis[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
