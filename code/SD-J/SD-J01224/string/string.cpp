#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int a[N];
char op[N];
long long ans;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i]>>op[i];
	}
	int l=1,r=n;
	while (l!=r) {
	//	cout<<l<<' '<<a[l]<<' '<<r<<' '<<a[r]<<'\n';
		if (l>r) break;
		if (op[l]==op[r]) {
			if (a[l]>a[r]) a[l]-=a[r],r--;
			else if (a[l]<a[r]) a[r]-=a[l],l++;
			else l++,r--;
		}
		else {
			if (a[l]>a[r]) a[l]-=a[r],ans+=a[r],r--;
			else if (a[l]<a[r]) a[r]-=a[l],ans+=a[l],l++;
			else ans+=a[l],l++,r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

//aaaddcbc
