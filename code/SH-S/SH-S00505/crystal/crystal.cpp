#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int suma,sumb,ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int midd=a[n/2];
	for (int i=0;i<n;i++){
		a[i]=abs(a[i]-midd);
		if (i<n/2){
			suma+=a[i];
		}
		else if (i>n/2){
			sumb+=a[i];
		}
	}
	if (suma<sumb){
		for (int i=n/2;i>=0;i--){
			m-=a[i];
			ans++;
			if (m<=0){
				break;
			}
		}
		int o=n/2+1;
		while(m>0){
			if (a[o]<=m){
				ans++;
				m-=a[o];
				o++;
			}
		}
	}
	else{
		for (int i=n/2;i<n;i++){
			m-=a[i];
			ans++;
			if (m<=0){
				break;
			}
		}
		int o=n/2-1; 
		while (m>0){
			if (a[o]<=m){
				ans++;
				m-=a[o];
				o--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
