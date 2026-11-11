#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nnnn {
	int sl;
	char c;
};
nnnn a[200005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0; i<n; i++) {
		cin>>a[i].sl>>a[i].c;
	}
	char l=a[0].c,r=a[n-1].c;
	int j=0,k=0,sum=0;
	int n2;
	if(n%2!=0) {
		n2=n/2+1;
	} else {
		n2=n/2;
	}
	while(j+k<n-1) {
		l=a[j].c;
		r=a[n-1-k].c;
		if(l!=r) {
			if(a[j].sl==a[n-1-k].sl) {
				sum+=a[j].sl;
				j++;
				k++;
				continue;
			}
			else{
				sum++;
			}
			
		} else if(l==r) {
			a[j].sl-=min(a[j].sl,a[n-k-1].sl);
			a[n-j-1].sl-=min(a[j].sl,a[n-k-1].sl);
			j+=min(a[j].sl,a[n-k-1].sl);
			continue;
		}

		a[j].sl--;
		a[n-k-1].sl--;
		if(a[j].sl==0) {
			j++;
		}
		if(a[n-k-1].sl==0) {
			k++;
		}

	}
	cout<<sum;
}

