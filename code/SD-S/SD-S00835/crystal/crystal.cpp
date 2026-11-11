//crystal
//Ë«Ö¸Õë 
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+505;
int n,ans;
long long m,a[N],f[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	int l=0,r=1;
	while(l<=n-1 && r<=n){
		while(l<r && a[r]*(r-l)-(f[r]-f[l])>m){
			l++;
		}
		if(l<=n-1)
			ans=max(ans,r-l);
		r++;
	}
	cout<< ans;
	return 0;
} 
