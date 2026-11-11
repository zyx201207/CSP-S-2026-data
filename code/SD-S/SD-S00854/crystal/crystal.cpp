#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n,m,a[N],f[N],ans[N],p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(a[i]-a[i-1])*(ans[i-1]);
		ans[i]=ans[i-1]+1;
		if(f[i]>m){
			while(f[i]>m&&ans[i]){
				f[i]-=(a[i]-a[i-ans[i]+1]);
				ans[i]--;
			}
		}
		//cout<<f[i]<<" "<<ans[i]<<'\n';
		p=max(p,ans[i]);
	}
	cout<<p;
	return 0;
}
