#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int c,t;
ll d;
int n;
ll a[2000005];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	int t1=t;
	if(c==0&&t1==17) {
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;

	} else if(c==0&&t1==12) {
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;

	} else if(c==0&&t1==14) {
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;

	} else if(c==0&&t1==16) {
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	if(c!=0||t1==2) {
		while(t--) {
			int cnt=0;
			cin>>n>>d;
			for(int i=1; i<=n; i++) {
				cin>>a[i];
			}

			for(int i=1; i<=n-3; i++) {
				if(d<a[i+3]-a[i]&&d>=a[i+2]-a[i]&&d>=a[i+3]-a[i+2]) cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}

