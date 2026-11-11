#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[200005];
	char c[200005];
	string s="",rs="";
	cin>>n;
	long long xxx=0,cnt=0;
 	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		xxx+=a[i];
	}
	long long l=1,r=n,b=0,ddd=0;
	char lc=c[1],rc=c[n];
	for (int i=1;i<=xxx/2;i++){
		if (lc!=rc){
			cnt+=1;
		}
		b++;
		ddd++;
		if (b>=a[l]){
			b-=a[l];
			l++;
			lc=c[l];
		}
		if (ddd>=a[r]){
			ddd-=a[r];
			r--;
			rc=c[r];
		}
	}
	cout<<cnt;
	return 0;
}