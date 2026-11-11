#include <bits/stdc++.h> 
using namespace std;
long long a[300000];
int main () {
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=0;i<=n;i++){
		cin >> a[i];
	}
	long long ans=0;
	/*
	for(int i=0;i<=n;i++){
		int s[200005]
		int j=0;
		while(j<=n){
			s[i]=a[i]&a[j];
			j++;
		}
		sort(s,s+n);
		ans=max(ans,s[s.size()-1]);
	}
	*/
	for(int i=0;i<=n;i++){
		long long an=a[i];
		for(int j=0;j<m;j++){
			an&=a[i+j];
		}
		if(an>ans)ans=an;
	}
	cout << ans;
	return 0;
}
