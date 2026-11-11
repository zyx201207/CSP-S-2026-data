#include<bits/stdc++.h>
using namespace std;

long long a[500005],b[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long l=2,r=2,t=1,maxx=0,sum=b[2];
	while (l != n){
		if (sum <= m){
			r++;
			t++;
			maxx=max(maxx,t);
			sum+=b[r]*(r-l);
		}else {
			l++;
			t--;
			sum-=b[l];
		}
	}
	cout<<maxx;
	return 0;
} 
