#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
struct aq {
	long long sum;
	string s;
} a[200005];
string ss;
void ppp(long long i,long long jj) {
	if(i>=jj) {
		return ;
	}
	if(a[i].s==a[jj].s) {
		if(a[i].sum==a[jj].sum) {
			jj--;
			i++;
			ppp(i,jj);
			return ;
		}
		if(a[i].sum<a[jj].sum) {
			a[jj].sum-=a[i].sum;
			i++;
			ppp(i,jj);
			return ;
		}
		if(a[i].sum>a[jj].sum) {
			a[i].sum-=a[jj].sum;
			jj--;
			ppp(i,jj);
			return ;
		}
	} else if(a[i].s!=a[jj].s) {
		if(a[i].sum==a[jj].sum) {
			cnt+=a[i].sum;
			jj--;
			i++;
			ppp(i,jj);
			return ;
		}
		if(a[i].sum<a[jj].sum) {
			cnt+=a[i].sum;
			a[jj].sum-=a[i].sum;
			i++;
			ppp(i,jj);
			return ;
		}
		if(a[i].sum>a[jj].sum) {
			cnt+=a[jj].sum;
			a[i].sum-=a[jj].sum;
			jj--;
			ppp(i,jj);
			return ;
		}
	}

}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int k=1; k<=n; k++) {
		scanf("%lld",&a[k].sum);
		cin>>a[k].s;
	}
	ppp(1,n);
	cout<<cnt;
	return 0;
}


