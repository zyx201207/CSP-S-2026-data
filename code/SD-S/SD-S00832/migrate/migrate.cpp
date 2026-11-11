#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n;
long long pre[N];
long long m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	pre[0]=0;
	for(int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
	int l=0,ans=0;
	for(int r=0;r<n;r++){
		while(1LL*a[r]-(r-l+1)-(pre[r+1]-pre[l])>m){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

