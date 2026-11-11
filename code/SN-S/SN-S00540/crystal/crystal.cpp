#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmpg(int a,int b) {
	return a<b;
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int had[n+1];
	for(int i=0; i<n; i++) {
		cin>>had[i];
	}
//	cout<<n<<endl<<m<<endl;
//	for(int i=0; i<n; i++) {
//		cout<<had[i]<<endl;
//	}
	sort(had+0,had+n,cmpg);
	int c[n+1],pd=0;
	for(int i=1; i<n; i++) {
		c[i]=had[i]-had[i-1];
	}
	int ans=0;
	for(int i=1; i<n; i++) {
		int cost=0,ans1=1,jj=0;
		for(int j=i; j>=0; j--) {
			jj+=c[j];
			cost+=jj;
			if(cost<=m) {
				ans1++;
			}
			ans=max(ans,ans1);
		}
//		cout<<ans1<<ans;
	}
	cout<<ans;
	return 0;
}
