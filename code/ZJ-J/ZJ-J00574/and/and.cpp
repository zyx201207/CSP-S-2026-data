#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans;
	for(int mx=n;mx>=m;mx--){
		int sum=a[mx];
		int k=1;
		for(int i=mx-1;i>=1;i--){
			if(k==m){
				break;
			}
			if(sum&a[i]){
				sum&=a[i];
				k++;
			}
		}
		if(k==m){
			ans=sum;
			break;
		}
	}
	cout<<ans;
	return 0;
}
