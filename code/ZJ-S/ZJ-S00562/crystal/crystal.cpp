#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],ans=0;
long long sz(int x){
	int l=x-1,r=x+1;
	int cnt=1;
	int u=m;
	while(1){
		if((l<1&&a[r]-a[x]>m)||(r>n&&a[x]-a[l]>m)||(l<1&&r>n))break;
		if(r>n){
			if(a[x]-a[l]<=m){
				cnt++;
				m-=a[x]-a[l];
				l--;
				continue;
			}
			break;
		}
		if(l<1){
			if(a[r]-a[x]<=m){
				cnt++;
				m-=a[r]-a[x];
				r++;
				continue;
			}
			break;
		}
		if(a[x]-a[l]>a[r]-a[x]&&r<=n){
			cnt++;
			m-=a[r]-a[x];
			r++;
		}
		else{
			cnt++;
			m-=a[x]-a[l];
			l--;
		}
	}
	m=u;
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long u=sz(i);
		if(u>ans)ans=u;
	}
	cout<<ans;
}