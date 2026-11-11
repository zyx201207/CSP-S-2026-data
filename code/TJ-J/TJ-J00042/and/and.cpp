#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,z,q,a[200020],an,b[200020],bb,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		z = max(a[i],z);
	}
	while(z>0){
		z/=2;
		an++;
	}
	for(int i = an;i>=0;i--){
		int mm = m;
		bb = 0;
		for(int j = 0;j<n;j++){
			if((a[j]>>i)%2 == 1){
				mm--;
				b[bb] = a[j];
				bb++;
			}
		}
		if(mm <= 0){
			sort(b+0,b+bb);
			for(int j = bb-1;j>=bb-m;j--){
				ans = ans&b[j];
				if(ans == 0&&j == bb-1) ans = b[j];
			}
			cout<<ans;
			return 0;
		}
	}
	sort(a+0,a+n);
	for(int j = n-1;j>=n-m;j--){
		ans = ans&a[j];
		if(ans == 0&&j == n-1) ans = a[j];
	}
	cout<<ans;
	return 0;
}
