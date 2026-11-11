#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long c[500005];
long long maxx=-1;
bool flag=0;
int d=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	int d=a[n]-a[n-1];
	for(int i=n-1;i>=2;i--){
		if(a[i]-a[i-1]==d){
			flag=1;
		}
	}
	if(flag==1){
		int t=0;
		for(int i=1;i<=n;i++){
			c[i]=(i*d*(i-1))/2;
		}
		for(int i=1;i<=n;i++){
			if(c[i]>m){
				t=i-1;
				break;
			}
		}
		cout<<t;
		return 0;
	}
	for(int i=2;i<=n;i++){
		long long t=m;
		long long cnt=1;
		for(int j=i-1;j>=1;j--){
			long long x=a[i]-a[j];
			if(t>=x){
				t-=x;
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
