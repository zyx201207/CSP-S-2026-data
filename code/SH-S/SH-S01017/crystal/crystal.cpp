#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
bool cmp(int x,int y) {
	return x<y;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=0;i<n;i++) {
		cin>>a[i]; 
		if(a[i]!=i+1) flag=false;
	}
	if(flag==true) {
		int aw=1;
		while(m>0) {
			m-=aw;
			aw++;
		}
		cout<<aw;
		return 0;
	}
	sort(a,a+n,cmp);
	long long maxans=-1e13;
	for(int i=1;i<n;i++) {
		long long t=m;
		int j=i-1;
		long long ans=0;
		while(j>=0) {
			if(t<(a[i]-a[j])) {
				break;
			}
			else {
				t-=(a[i]-a[j]);
				ans++;
				j--;
			}
		}
		if(ans>maxans) maxans=ans;
	}
	cout<<maxans+1;
	return 0;
} 
