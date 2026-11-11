#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long a[MAXN];
char c[MAXN];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	
	long long l=1,r=n;
	long long sum=0,s;
	s=a[l]>a[r]?a[l]:a[r];
	while(l<r) {
		if(a[l]>=a[r]&&c[l]==c[r]&&s!=0) {
			if(s>=a[r]) {
				a[l]-=a[r];
				s-=a[r];
			}
			else{
				a[l]-=s;
				a[r]-=s;
			}r--;
		} else if(a[l]<a[r]&&c[l]==c[r]&&s!=0) {
			if(s>=a[l]) {
				a[r]-=a[l];
				s-=a[l];
			}
			else{
				a[r]-=s;
				a[l]-=s;
			}l++;
		}
		if(a[l]>=a[r]&&c[l]!=c[r]&&s!=0) {
			if(s>=a[r]) {
				a[l]-=a[r];
				s-=a[r];
				sum+=a[r];
			}
			else{
				a[l]-=s;
				a[r]-=s;
				sum+=s;
			}r--;
		} else if(a[l]<a[r]&&c[l]!=c[r]&&s!=0) {
			if(s>=a[l]) {
				a[r]-=a[l];
				s-=a[l];
				sum+=a[l];
			}
			else{
				a[r]-=s;
				a[l]-=s;
				sum+=s;
			}l++;
		}
		if(s==0) {
			s=a[l]>a[r]?a[l]:a[r];
		}
	}
	cout<<sum;
	return 0;
}
