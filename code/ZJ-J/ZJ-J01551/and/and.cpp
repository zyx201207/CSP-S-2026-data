#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,ans,pw[31];
bool a[31][200005],vis[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	pw[0]=1;
	for(int i=1;i<=30;i++){
		pw[i]=pw[i-1]*2;
	}
	for(int i=1;i<=n;i++) vis[i]=1;
	for(int i=1;i<=n;i++){
		int x,st=0;
		cin >> x;
		while(x){
			if(x%2==1){
				a[st][i]=1;
			}
			x/=2;
			st++;
		}
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(vis[j] && a[i][j]){
				sum++;
			}
		}
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(vis[j] && a[i][j]==0){
					vis[j]=0;
				}
			}
			ans+=pw[i];
		}
	}
	cout << ans;
	return 0;
}
