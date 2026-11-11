#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=1,mm=m,w=i-1;
		while(mm>=a[i]-a[w]&&w>=1){
			cnt++;
			mm-=(a[i]-a[w]);
			w--;
		}
		ans=max(ans,cnt);
	} 
	cout<<ans;
	return 0;
} 
