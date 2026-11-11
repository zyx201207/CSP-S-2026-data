#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mx=INT_MIN; 
const int N=2e5+5;
int a[N],b[N],cnt;
bool f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if((a[i]+1)%2==1) f=1;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(f==0){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	sort(a+1,a+n+1);
	int sum=a[n];
	for(int i=n-1;i>=1;i--){
		m--;
		sum=sum&a[i];
		if(m==0) break;
	}
	cout<<sum;
	return 0;
}
