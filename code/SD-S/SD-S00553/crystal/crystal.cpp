#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N],sum[N];
int cnt1,cnt2=2;
long long cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==i) cnt1++;
		if(i>=2){
			if(i==2) cnt=abs(a[i]-a[i-1]);
			else if(abs(a[i]-a[i-1])==cnt) cnt2++;
		}
	}
	sort(a+1,a+n+1); 
	if(cnt1==n){
		int ans1=1;
		while(m>=ans1){
			m-=ans1;
			ans1++;
		}
		if(ans1<=n) cout << ans1;
		else cout << n;
	}else if(cnt2==n){
		int ans2=1;
		int sum=cnt;
		while(m>=sum){
			m-=sum;
			ans2++;
			sum*=ans2;
		}
		if(ans2<=n) cout << ans2;
		else cout << n;
	}else{
		int maxx=0;
		for(int i=2;i<=n;i++){
			sum[i]=( a[i]-a[i-1] )*(i-1)+sum[i-1];
			if(sum[i]<=m) maxx=i-1;
		}
		for(int i=2;i<=n-maxx;i++){
			for(int j=i+maxx+1;j<=n;j++){
				if(( sum[j]-sum[i]-(a[j]-a[i])*(i-1) ) <= m){
					maxx=j-i;
				}else continue;
			}
		}
		cout << maxx+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
