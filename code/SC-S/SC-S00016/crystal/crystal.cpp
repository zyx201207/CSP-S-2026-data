#include<bits/stdc++.h>
using namespace std;
int n,ans=1,v=1;
long long m,a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int s=a[2]-a[1];
	for(int i=2;i<=n;i++) if(a[i]-a[i-1]==s) v++;
	if(v==n){
		m=m*2/s;
		int d=1;
		for(int i=1;;i++){
			if(m-i>=0){
				d=i;
				m-=i;
			}
			else break;
		}
		cout<<d;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x=1;
		long long y=0;
		for(int j=i+1;j<=n;j++){
			y=y+x*(a[j]-a[j-1]);
			if(y<=m) x++;
			else break;
		}
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}