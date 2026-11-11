#include<bits/stdc++.h>
#define int long long
#define INF (1ll<<62)
#define pii pair<int,int>
using namespace std;
int n,m;
int a[500010];
bool fg=0;
int s[500010];
int last[50100];
bool f[50010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[0]=-INF;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])  fg=1;
	}
	if(n<=5 and m<=2){
		if(m==1){
			cout<<n;
			return 0;
		} 
		int sum=0;
		for(int i=1;i<n;i++){
			if(a[i]!=a[n])  sum++;
		}
		if(a[n]==1)  cout<<n<<" "<<sum;
		else cout<<sum<<" "<<n;
		return 0;
	}
	else if(!fg){
		int sum=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1])  cout<<sum<<" ";
			sum++;
		} 
		cout<<sum;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof f);
			for(int j=i;j<=n;j++){
				if(a[j]==a[n])  break;
				if(!f[a[j]]){
					last[a[j]]++;
					f[a[j]]=1;
				}
			}
		}
		for(int i=1;i<=m;i++)  cout<<last[i]<<" ";
	}
	return 0;
}

