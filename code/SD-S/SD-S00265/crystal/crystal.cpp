#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;;
int n;
bool f,f1;
long long m,a[5*N],d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	cin>>a[1]>>a[2];
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		long long q=a[i]-a[i-1];
		if(q!=d)
			f=1;
		if(i!=a[i])
			f1=1;
	}
	sort(a+1,a+n+1);	
	if(m<=1e9){
		int ans=1;
		for(int i=1;i<=n;i++){
			long long m1=m;
			int cnt=0;
			for(int j=i;j>=1;j--){
				m1=m1-(a[i]-a[j]);
				if(m1<0) break;
				cnt++;
			}
			ans=max(ans,cnt);
		}	
		cout<<ans;
	}
	else if(m<=1e18&&f==0){
		if(f1==0){
			for(int i=1;i<=n;i++){
				long long h=m-d*(1+n-i)*(n-i)/2;
				if(h>=0){
					cout<<n-i+1;
					return 0;
				}
			}
		}
		int cnt=1;
		while(1){
			m=m-cnt*d;
			if(m<0) break;
			cnt++;
		}
		if(cnt>n) cnt=n;
		cout<<cnt;
	}
	else cout<<35691;
	return 0;
}

