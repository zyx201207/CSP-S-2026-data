#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],s[N];
long long ans=-1;
bool ff(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		s[i]=a[n]-a[i];
	}
	if(ff()){
		long long T=abs(a[2]-a[1]);
		cout<<ceil((sqrt(1+8*m/T)-1)/2);
		return 0;
	}
	long long cnt=m,sum=1;
	for(int i=n;i>=1;i--){
		cnt=m;
		sum=1;
		for(int j=i-1;j>=1;j--){
			if(cnt<(s[j]-s[i])){
				break;
			}
			cnt-=(s[j]-s[i]);
			sum++;
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
