#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],s,maxs;
bool b=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]!=i){
			b=0;
		}
	}
	sort(a+1,a+n+1);
	if (b){
		long long sc=0;
		for (int i=1;i<=n;i++){
			sc+=a[i];
		}
		sc/=n;
		int z=0;
		for (int i=1;i<=n;i++){
			if (a[i]>=sc){
				z=i;
				break;
			}
		}
		for (int i=1;i<=z;i++){
			long long c1=0,s1=0;
			for (int j=1;j<=i;j++){
				c1+=sc-a[j];
				if (c1>m){
					break;
				}
				else{
					s1++;
				}
			}
			if (s1>maxs){
				maxs=s1;
			}
		}
		cout << maxs;
		return 0;
	}
	for (int i=1;i<=n;i++){
		long long c=0;
		s=0;
		for (int j=1;j<=i;j++){
			c+=a[i]-a[j];
			if (c>m){
				break;
			}
			else{
				s++;
			}
		}
		if (s>maxs){
			maxs=s;
		}
	}
	cout << maxs;
	return 0;
}
