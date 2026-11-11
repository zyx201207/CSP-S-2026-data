#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
struct Node {
	int x;
	bool f;
};
Node a[N];

bool cmp(Node a,Node b) {
	if(a.f!=b.f) return a.f<b.f;
	return a.x>b.x;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i].x;
		a[i].f=0;
	}
	int ans=0;
	for(int i=30; i>=0; i--) {
		sort(a+1,a+1+n,cmp);
		int sum=0;
		for(int j=1; j<=n; j++) {
			if(a[j].f) break;
			if((a[j].x&(1<<i))) sum++;
		}
		if(sum>=m) {
			for(int j=1; j<=n; j++){
				if(a[j].f) break;
				if(!(a[j].x&(1<<i))) a[j].f=1;
			}
			ans+=(1<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
