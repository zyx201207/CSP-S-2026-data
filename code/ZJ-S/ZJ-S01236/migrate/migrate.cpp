#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,n,d,t;
long long x[N];
int find2(int l,int r,int pre,int last) {
	int no1=0;
	for(int i=l; i<=r; i++) {
		if(x[last+1]-x[i]>d) no1+=1;
		else break;
	}
	int no2=0;
	for(int i=r; i>=l; i--) {
		if(x[i]-x[pre-1]>d) no2+=1;
		else break;
	}
	return 2*no1*no2;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		scanf("%d%d",&n,&d);
		for(int i=1; i<=n; i++) {
			scanf("%d",&x[i]);
		}
		if(c==11||c==12) {
			int num=d/(x[2]-x[1]);
			if(num<2) cout<<0<<endl;
			else cout<<1<<endl;
		} else if(c==13||c==14) {
			int num=0,pre=n+1,last=0;
			for(int i=1; i<=n; i++) {
				if(x[n]-x[i]<=d&&x[i]-x[1]<=d) {
					num+=1;
					pre=min(pre,i);
					last=max(last,i);
				}
			}
			if(num>=3) cout<<0<<endl;
			else if(num==2) {
                cout<<find2(1,n,pre,last)<<endl;
			} else {
				int can=1;
				while(x[pre+1]-x[can]>d) can+=1;
				int ans=0;
				ans+=find2(can,n,pre,last+1);
				can=n;
				while(x[can]-x[pre-1]>d) can-=1;
				ans+=find2(can,n,pre-1,last);
				cout<<ans<<endl;
			}
		} else cout<<0;
	}
	return 0;
}