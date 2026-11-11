#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,a[N];
long long ans;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)	cin >> a[i] >> b[i];
	int l = 1,r = n;
	while(l<r){
		if(b[l]!= b[r]){
			if(a[l]>a[r]){
				r--;
				a[l]-=a[r];
				ans+=a[r]*1LL;
			}else if(a[l]<a[r]){
				l++;
				a[r]-=a[l];
				ans+=a[l]*1LL;
			}else{
				l++,r--;
				ans+=a[l]*1LL;
			}
		}else{
			if(a[l]>a[r]){
				r--;
				a[l]-a[r];
			}else if(a[l]<a[r]){
				l++;
				a[r]-=a[l];
			}else	l++,r--;
		}	
	}
	cout << ans << '\n';
	return 0;
}

