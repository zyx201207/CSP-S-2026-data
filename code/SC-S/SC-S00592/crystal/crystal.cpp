#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int s[500005];
int mx=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=n;i>=1;i--){
		int xh=0,ans=1,w=i;
		while(w>1){
			w--;
			if(m>=xh+s[i]-s[w]){
				ans++;
				xh+=(s[i]-s[w]);
			}else{
				break;
			}
		}
		if(w==0){
			break;
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}
