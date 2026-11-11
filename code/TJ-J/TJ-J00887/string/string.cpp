#include <bits/stdc++.h>
using namespace std;
int a[200010],n,cnt;
string c[200010],sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++){
			sum=sum+c[i];
		}
	}
	for(int i=0;i<sum.size()/2;i++){
		if(sum[i]!=sum[sum.size()+1-i]){
			sum[sum.size()+1-i]=sum[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
