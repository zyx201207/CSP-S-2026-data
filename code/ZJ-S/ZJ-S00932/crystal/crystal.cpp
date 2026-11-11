#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long d[500005];
bool v=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=4){
			if(a[i-3]-a[i-2]!=a[i-1]-a[i]) v=0;
		}
	}
	if(v){
		long long i=a[2]-a[1],cnt=0;
		while(m>=0){
			m-=i;
			i=i+a[2]-a[1];
			cnt++;
		}
		cout<<min(cnt,n);
		return 0;
	}
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		int x=m;
		d[i]++;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=x){
				x=x-a[i]+a[j];
				d[i]++;
				//cout<<i<<' '<<j<<' '<<x<<endl;
			}
			else break;
		}
	}
	long long maxx=-1;
	for(int i=0;i<n;i++){
		maxx=max(maxx,d[i]);
	}
	cout<<maxx;
	return 0;
} 
