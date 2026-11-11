#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int ans;
int v[N];
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=30;j>=0;j--){
		int g=0;
		for(int i=1;i<=n;i++){
			if(v[i])continue;
			if(a[i]&(1<<j))g++;
		}
		if(g>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;i++){
				if(v[i])continue;
				if(!(a[i]&(1<<j)))v[i]=true;
			}
		}
	}
	cout<<ans;
	return 0;
}
