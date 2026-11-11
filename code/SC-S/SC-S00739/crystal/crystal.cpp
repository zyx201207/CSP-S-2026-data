#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int a;
	int cha;
};
node x[500010];
int n,m,mx=0,b[500010];
bool cmp(node x,node y) {
	return x.a<=y.a;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>x[1].a;
	b[1]=x[1].a;
	for(int i=2; i<=n; i++) {
		cin>>x[i].a;
		b[i]=b[i-1]+x[i].a;
	}
	sort(x+1,x+1+n,cmp);
	if((x[1].a+x[n].a)*n/2==b[n]) {
		int y=b[3];
		int i=0;
		for(;; i++) {
			if(m-i*y>=0)m-=i*y;
			else break;
		}
		cout<<min(i-1,n);
		return 0;
	} else {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				x[j].cha=x[i].a-x[j].a;
			}
			int sum=0,y=m;
			for(int j=i; j>=1; j--) {
				if(y-x[j].cha>=0) {
					sum++;
					y-=x[j].cha;
				} else {
					break;
				}
				mx=max(mx,sum);
			}
		}
		cout<<mx;
	}
	return 0;
}