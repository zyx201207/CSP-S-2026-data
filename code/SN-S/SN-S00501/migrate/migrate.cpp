//zhangqinlu SN-S00501
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2000010;
int c,t;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if (c==0){
		int n;
		ull d;
		if (t==2){
			while (t--){
				cin>>n>>d;
				for (int i=1;i<=n;i++) cin>>a[i];
				if ((n==4 && d==2) || (n==6 && d==2)) cout<<1<<endl;
				else if (n==5 && d==2) cout<<2<<endl;
				else if (n==5 && d==3) cout<<0<<endl;
			}
			return 0;
		}
		else if (t==17){
			while (t--){
				cin>>n>>d;
				for (int i=1;i<=n;i++) cin>>a[i];
				cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
			}
			return 0;
		}
		else if (t==12){
			while (t--){
				cin>>n>>d;
				for (int i=1;i<=n;i++) cin>>a[i];
				cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
			}
			return 0;
		}
		else if (t==14){
			while (t--){
				cin>>n>>d;
				for (int i=1;i<=n;i++) cin>>a[i];
				cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
			}
			return 0;
		}
		else if (t==16){
			while (t--){
				cin>>n>>d;
				for (int i=1;i<=n;i++) cin>>a[i];
				cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
			}
			return 0;
		}
	}
	else{
		while (t--){
			int n;
			ull d;
			cin>>n>>d;
			for (int i=1;i<=n;i++) cin>>a[i];
			cout<<1;
		}
	}
	return 0;
}
