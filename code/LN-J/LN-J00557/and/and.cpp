#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int cnt=a[1];
		for(int i=1;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==2){
		int mx=a[1]&a[2];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1){
		int mx=-1,cnt;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==1) cnt=a[2];
				else cnt=a[1];
				if(j==i) continue;
				cnt=cnt&a[j];
			}
			mx=max(mx,cnt);
		}
		cout<<mx;
		return 0;
	}
	sort(a+1,a+1+n);
	int cnt=a[n];
	for(int i=n;i>=n-m+1;i--){
		cnt=cnt&a[i];
	}
	cout<<cnt;
	return 0;
}
