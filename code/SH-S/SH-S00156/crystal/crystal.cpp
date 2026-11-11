#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,m,a[500010],d,mmaxn;
bool flagA=1;
long long calc(long long x){
	return x * (x+1) / 2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		mmaxn == max(mmaxn,a[i]);
	}
	int d = a[2]-a[1];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) if(a[i]-a[i-1] != d) flagA=0;
	if(n <= 5000){
		for(int i=1;i<=n;i++){
			//¼ÙÉèa[i]
			long long m1=m,sum=1;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j] <= m1){
					m1 -= a[i]-a[j];
					sum++;
				}else break;
			} 
			ans = max(ans,sum);
		}
		cout << ans<<' ';
		return 0;
	}
	else if(flagA){
			long long L=1,R=1e9;
			while(L+1<R){
				long long M = (L+R)/ 2;
				if(d * calc(M) <= m) L=M;
				else R=M;
			} 
			cout << L+1;	
	}
	else{
		int x=0;
		for(int i=1;i<=n;i++){
			long long L=1,R=i+1;
			while(L+1<R){
				long long M = (L+R)/2;
				if(M==i+1) R=M;
				if(M==1) L=M;
				if(a[i]-a[M]+x*(i-M) <= m) R=M;
				else L=M;
			}
			x += a[i+1]-a[i];
			ans = max(ans,i-R+1);
		}
		cout << ans;
	}
}
