#include <bits/stdc++.h>
using namespace std;
long long n,m,a[550000],ans[350000];
long long top;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		long long q[550000];
		top=0;
		for(int j=i;j<=n;j++){
			long long x=a[j];
			bool s=0;
			for(int k=1;k<=top;k++){
				if(q[k]==x){
					top=k;
					q[top]=x;
					s=1;
				}
			}
			if(!s) q[++top]=a[j];
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=top;k++){
				if(q[k]==j){
					ans[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] <<' ';
	}
	return 0;
}
