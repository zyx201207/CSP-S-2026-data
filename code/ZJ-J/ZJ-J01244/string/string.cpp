#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long b[200010];
char c[200010];
char d[200010];
long long s[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long s=0,l=1,r=1;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		b[n-i+1]=a[i];
		d[n-i+1]=c[i];
	}
	long long ans=0;
	while(l<=n&&r<=n){
		if(c[l]!=d[r]){
			if(a[l]>b[r]){
				a[l]-=b[r];
				ans+=b[r++];
			}else if(a[l]<b[r]){
				b[r]-=a[l];
				ans+=a[l++];
			}else{
				ans+=a[l++];
				r++;
			}
		}else{
			int k=min(a[l],b[r]);
			a[l]-=k;
			b[r]-=k;
			if(a[l]==0){
				l++;
			}
			if(b[r]==0){
				r++;
			}
		}
	}
	cout << ans/2;
	return 0;
}
