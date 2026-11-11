#include <bits/stdc++.h>
using namespace std;
int n,tpa=1,tpb=1;
long long m;
int a[500005];
int b[500005];
int ans,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=abs(a[i]-a[i-1]);
		if(a[i]!=i){
			tpa=0;
		}
		if(i>=3){
			if(b[i]!=b[i-1]){
				tpb=0;
			}
		}
	}
	long long cnt=0;
	if(tpa==1){
		while(cnt<=m){
			cnt+=sum+1;
			sum++;
		}
		cout << sum;
		return 0;
	}
	if(tpb==1){
		while(cnt<=m){
			cnt+=sum+b[2];
			sum++;
		}
		cout << sum;
		return 0;
	}
	for(int i=2;i<=n;i++){
		cnt=0;
		sum=0;
		for(int j=i;j<=n;j++){
			cnt+=b[j];
			sum++;
			if(cnt>m){
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout << ans;
	return 0;
}
