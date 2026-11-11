#include<bits/stdc++.h>
using namespace std;
long long a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin >> n;
	long long m;
	cin >> m;
	if(m==0) cout << 1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int t1=0,t2=0;
	for(int i=1;i<=n;i++){
		if(i<n&&a[i+1]-a[i]==1) t1++;
		if(i<n-1&&a[i+1]-a[i]==a[i+2]-a[i+1]) t2++;
	}
	if(t1==n-1){
		int ans=1;
		int cha=1;
		while(m>=cha&&ans!=n){
			m-=cha;
			ans++;
			cha++;
		}
		cout << ans;
		return 0;
	}
	if(t2==n-2){
		int ans=1;
		long long cha=a[2]-a[1];
		while(m>=cha&&ans!=n){
			m-=cha;
			ans++;
			cha+=a[2]-a[1];
		}
		cout << ans;
		return 0;
	}
	int sum=1;
	int ans=0;
	long long p=0;
	for(int i=2;i<=n;i++){
		ans=0;
		int t=i;
		p=m;
		while(p>=(a[t]-a[t-1])&&ans!=i&&t>1){
			p=p-(a[t]-a[t-1]);
			t--;
			ans++;
		}
		sum=max(sum,ans+1);
	}
	cout << sum;
	return 0;
}
