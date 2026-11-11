#include <bits/stdc++.h>
using namespace std;
long a[200005],b[200005];

int main (){
	int n,m,cnt;
	long ans=0;
	cin >> n >> m;
	int p=n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=29;i>=-1;i--){
		cnt=1;
		long long k=pow(2,i);
		for(int j=1;j<=p;j++){
			if((a[j]-ans)>=k){
				b[cnt]=a[j];
				cnt++;
			}
		}
		if(cnt>m){
			for(int j=1;j<cnt;j++){
				a[j]=b[j];
			}
			p=cnt-1;
			ans+=k;
		}
	}
	cout << ans;
	return 0;
}