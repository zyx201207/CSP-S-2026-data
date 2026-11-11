#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],ans=-1;
bool vis[200005];
void cnt(long long int t,long long int l){
	if(t==0){
		ans=max(ans,l);
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			cnt(t-1,(l&a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		vis[i]=1;
		cnt(m-1,a[i]);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
