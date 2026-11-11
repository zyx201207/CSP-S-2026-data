#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,mx,k,ans;
int a[N];
bool vis[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	while(mx){
		mx/=2;
		k++;
	}
	int pos=pow(2,k-1);
	for(int i=1;i<=k;i++){ 
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(a[j]>=pos)cnt++;
		}
		if(cnt>=m)ans+=pos;
		for(int j=1;j<=n;j++){
			if(a[j]>=pos)a[j]-=pos;
			else if(cnt>=m)vis[j]=1;
		}
		pos/=2;
	}
	cout<<ans;
	return 0;
} 
