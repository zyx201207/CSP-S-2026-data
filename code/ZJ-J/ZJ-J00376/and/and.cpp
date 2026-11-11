#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a[200010][32],vis[200010];
int pw2[32]={1};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=1;i<=30;i++) pw2[i]=pw2[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		for(int j=30;j>=0;j--){
			if(tmp>=pw2[j]) tmp-=pw2[j],a[i][j]=1;
		}
	}
	int b=0,ans=0;
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i] && a[i][j]==1) cnt++;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(!vis[i] && a[i][j]!=1) vis[i]=1;
			}
			ans+=pw2[j];
		}
	}
	cout<<ans;
	return 0;
}
