#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n+10];
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long ans=1,p=m;
	for (int i=2;i<=n;i++){
		if ((a[i]-a[i-1])*(i-1)<=p){
			p=p-(a[i]-a[i-1])*(i-1);
			ans++;
		}
		else break;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
