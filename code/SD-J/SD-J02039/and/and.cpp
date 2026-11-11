#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				ans=max(ans,(a[i]&a[j]));
				//cout<<(a[i]|a[j])<<' ';
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=(pow(2,31)-1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	int t=pow(2,n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=t;i++){
		int cnt=0,b=i;
		long long k=(pow(2,21)-1);
		for(int j=1;(j<=n)&&b;j++){
			if(b%2==1){
				k=(k&a[j]);
				cnt++;
			}
			b/=2;
		}
		if(cnt==m){
			ans=max(ans,k);
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
4 3
1 1 1 1
5 3
31 3 1 15 7
//10:24!
*/
